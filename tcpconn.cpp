#include "tcpconn.h"

TcpConn::TcpConn(QObject *parent):QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(OnDataRev()));
    connect(this, SIGNAL(disconnected()), this, SLOT(OnDisconnected()));
}
TcpConn::~TcpConn(){
    disconnect(this, SIGNAL(readyRead()), this, SLOT(OnDataRev()));
    disconnect(this, SIGNAL(disconnected()), this, SLOT(OnDisconnected()));
}
void TcpConn::OnSlotDisconnected(){
    emit Disconnected(this->socketDescriptor());
}
