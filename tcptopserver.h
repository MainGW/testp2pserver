#ifndef TCPTOPSERVER_H
#define TCPTOPSERVER_H

#include <QMainWindow>
#include "tcpmeta.h"
#include "abstracttcpserver.h"
#include "ui_tcptopserver.h"
class TcpTopServer : public QMainWindow
{
    Q_OBJECT

public:
    TcpTopServer(QWidget *parent = nullptr);
    ~TcpTopServer();
public slots:
    void OnSlotOpenServer();
    void OnServerUpdate(tpkg::tpkgfull *, int);
private:
    Ui::TcpTopServer *ui;
    AbstractTcpServer *server;
};
#endif // TCPTOPSERVER_H
