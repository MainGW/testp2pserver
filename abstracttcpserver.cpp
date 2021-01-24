#include "abstracttcpserver.h"

AbstractTcpServer::AbstractTcpServer(QObject *parent, int port):QTcpServer(parent)
{

}
AbstractTcpServer::~AbstractTcpServer()
{

}
void AbstractTcpServer::NewConn(int sd)
{

}
QTcpSocket *AbstractTcpServer::findSocket(unsigned short vna){

}
void AbstractTcpServer::OnDisconnected(unsigned short vna){

}
