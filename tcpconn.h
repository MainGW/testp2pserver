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
    void virtual Disconnected(int)=0;
protected slots:
    void virtual OnDataRev()=0;
    void OnSlotDisconnected();
};

#endif // TCPCONN_H
