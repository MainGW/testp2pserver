#ifndef TCPCONN_H
#define TCPCONN_H

#include <QObject>
#include <QTcpSocket>
#include "tcpmeta.h"
class TcpConn:public QTcpSocket
{
    Q_OBJECT
public:
    TcpConn(QObject *parent);
    ~TcpConn();
    TcpMeta meta;
signals:
    void Disconnected(int);
protected slots:
    void OnDataRev();
    void OnSlotDisconnected();
};

#endif // TCPCONN_H
