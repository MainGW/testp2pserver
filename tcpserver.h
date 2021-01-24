#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include "abstracttcpserver.h"
class TcpServer:public AbstractTcpServer
{
    Q_OBJECT
public:
    TcpServer();

};

#endif // TCPSERVER_H
