#ifndef AbstractTcpServer_H
#define AbstractTcpServer_H

#include <QObject>
#include <QTcpServer>
#include <QPair>
#include <QList>
#include <QSqlDatabase>
#include "tcpconn.h"

class AbstractTcpServer:public QTcpServer
{
    Q_OBJECT
public:
    AbstractTcpServer(QObject *parent=NULL, int port=0);
    ~AbstractTcpServer();
    QList<QPair<TcpConn *, unsigned short>> tcpconns;
    typedef enum{
        updatename=0, updatedbgmsg, removename
    }opersm;
    TcpMeta meta;
    QSqlDatabase serverdb;
signals:
    void UpdateServer(tpkgfull *, int);
private slots:
    void OnDisconnected(int);
    QTcpSocket *findSocket(unsigned short);
protected:
    void NewConn(int);
};

#endif // AbstractTcpServer_H
