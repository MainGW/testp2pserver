#include "tcptopserver.h"
#include "ui_tcptopserver.h"
#include <QStandardItemModel>
TcpTopServer::TcpTopServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TcpTopServer)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(OnSlotOpenServer()));
    server=NULL;
}

TcpTopServer::~TcpTopServer()
{
    delete ui;
}

void TcpTopServer::OnSlotOpenServer(){
    int port = ui->lineEdit->text().toInt();
    server = new AbstractTcpServer(this, port);
    //server->serverdb = QSqlDatabase::addDatabase("QMYSQL");
    //server->serverdb.setHostName("localhost");
    QStandardItemModel *model = new QStandardItemModel();
    QStandardItemModel *model2 = new QStandardItemModel();
    model->appendRow(new QStandardItem("PSPSP"));
    model2->appendRow(new QStandardItem("[MESSAGE FROM:0 TO:0]PSPSP"));
    ui->listView->setModel(model);
    ui->listView_2->setModel(model2);
}
void TcpTopServer::OnServerUpdate(tpkgfull *fpkg, int num){

}
