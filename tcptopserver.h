#ifndef TCPTOPSERVER_H
#define TCPTOPSERVER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TcpTopServer; }
QT_END_NAMESPACE

class TcpTopServer : public QMainWindow
{
    Q_OBJECT

public:
    TcpTopServer(QWidget *parent = nullptr);
    ~TcpTopServer();

private:
    Ui::TcpTopServer *ui;
};
#endif // TCPTOPSERVER_H
