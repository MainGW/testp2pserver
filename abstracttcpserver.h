#ifndef ABSTRACTTCPSERVER_H
#define ABSTRACTTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QPair>
#include <QList>
#include "tcpmeta.h"
#include "tcpconn.h"
class AbstractTcpServer:public QTcpServer
{
    Q_OBJECT
public:
    AbstractTcpServer(QObject *parent=NULL, int port=0);
    ~AbstractTcpServer();
    QList<QPair<TcpConn *, unsigned short>> tcpconns;
    enum opers{
        updatename=0, updatedbgmsg, removename
    };
signals:
    void ServerUpdate(tpkgfull *, int, opers);
private slots:
    void OnDisconnected(unsigned short);
    QTcpServer *findSocket(unsigned short);
protected:
    void NewConn(int);
};

#endif // ABSTRACTTCPSERVER_H
