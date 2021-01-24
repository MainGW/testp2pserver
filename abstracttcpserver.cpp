#include "abstracttcpserver.h"

AbstractTcpServer::AbstractTcpServer(QObject *parent, int port):QTcpServer(parent)
{
    listen(QHostAddress::Any, port);
}
AbstractTcpServer::~AbstractTcpServer()
{
    for(int i = 0;i < tcpconns.count();i++)
        delete tcpconns.at(i).first;
}
void AbstractTcpServer::NewConn(int sd)
{
    TcpConn *conn = new TcpConn(this);
    connect(conn, SIGNAL(OnSlotDisconnected(int)), this, SLOT(OnDisconnected(int)));
    conn->setSocketDescriptor(sd);
    unsigned short vna = 0xFFFF;
    QPair<TcpConn *, unsigned short> p(conn, vna);
    tcpconns.append(p);

}
QTcpSocket *AbstractTcpServer::findSocket(unsigned short vna)
{
    int i = 0;
    for(i = 0;i < tcpconns.count();i++){
        if(tcpconns.at(i).second == vna){
            return tcpconns.at(i).first;
        }
    }
    return nullptr;
}
void AbstractTcpServer::OnDisconnected(int sd)
{
    int i = 0;
    for(i = 0;i < tcpconns.count();i++){
        if(tcpconns.at(i).first->socketDescriptor() == sd){
            emit UpdateServer(meta.makePack(MESSAGE,"RemoveName", 0, 0), i);
            tcpconns.removeAt(i);
            break;
        }
    }
}
