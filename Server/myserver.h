#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include<QTcpServer>
#include<QTcpSocket>
#include <string>
using namespace std;

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    MyServer(QObject *parent = 0,int port=2000);

signals:


public slots:
    void goOn();

private:
    QString str;

};

#endif // MYSERVER_H
