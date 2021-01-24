#include "tcptopserver.h"
#include "ui_tcptopserver.h"

TcpTopServer::TcpTopServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TcpTopServer)
{
    ui->setupUi(this);
}

TcpTopServer::~TcpTopServer()
{
    delete ui;
}

