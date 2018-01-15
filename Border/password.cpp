#include "password.h"
#include<QMainWindow>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include "window.h"
#include <QString>
#include<string>
#include <cstring>
#include <QTcpSocket>


using namespace std;


PassWord::PassWord()
{
    setWindowTitle("Authentication!");
    setFixedSize(300,200);


    ip = new QLabel(this);
    username = new QLabel(this);
    password = new QLabel(this);
    ip1 = new QLineEdit(this);
    username1 = new QLineEdit(this);
    password1 = new QLineEdit(this);
    submitbutton = new QPushButton(this);
    termi = new QPushButton(this);

    ip->setText("<H3>IP ADDRESS: </H3>");
    ip->resize(100,50);
    ip->move(20,10);

    username->setText("<H3>USER ID: </H3>");
    username->resize(100,50);
    username->move(20,60);

    password->setText("<H3>PASSWORD: </H3>");
    password->resize(100,50);
    password->move(20,110);

    submitbutton->setText("Submit");
    submitbutton->move(120,160);

    termi->setText("Terminate");
    termi->move(200,160);

    ip1->move(110,15);
    ip1->resize(100,30);
    username1->move(110,70);
    username1->resize(100,25);
    password1->setEchoMode(QLineEdit::Password);
    password1->move(110,120);
    password1->resize(100,25);

    setWindowFlags(Qt::Window
    | Qt::WindowMinimizeButtonHint
    | Qt::WindowMaximizeButtonHint);

    setModal(true);
    connect(submitbutton,SIGNAL(clicked(bool)),this,SLOT(submit()));
    connect(termi,SIGNAL(clicked(bool)),this,SLOT(out()));


}

void PassWord::submit()
{


    QString info;
    string infostd;
    char message[40];

    info = ip1->text();
    infostd = info.toStdString();

    QTcpSocket* socket = new QTcpSocket(this);
    socket->connectToHost(infostd.c_str(),2000);
    strcpy(message,infostd.c_str());
    emit ipchange(message);

    if(socket->waitForConnected(1000))
    {
        socket->waitForReadyRead();
        info = socket->readAll();

        if(info=="Y")
        {
            socket->flush();
            socket->write("1");
            socket->waitForBytesWritten(1000);

            socket->waitForReadyRead();
            info = socket->readAll();

            if(info == "A")
            {
            info = username1->text();
            infostd = info.toStdString();
            strcpy(message,infostd.c_str());
            emit setpost(message);
            strcat(message,"/");

            info =password1->text();
            infostd = info.toStdString();
            strcat(message,infostd.c_str());

            socket->flush();
            socket->write(message);
            socket->waitForBytesWritten(1000);

            socket->waitForReadyRead();
            info = socket->readAll();

            if(info == "DONE")
            {
            emit submitted();
            this->close();
            }
            else
            {
                            mes= new QLabel(this);
                            mes->move(10,170);
                            mes->setText("<Font color = #FF0000>ERROR! </Font>");
                            mes->show();
            }


            }
            else{
                mes= new QLabel(this);
                mes->move(10,170);
                mes->setText("<Font color = #FF0000>ERROR! </Font>");
                mes->show();
                }


        }
        else{
            mes= new QLabel(this);
            mes->move(10,170);
            mes->setText("<Font color = #FF0000>ERROR!</Font>");
            mes->show();
        }


    }
    else{
        mes= new QLabel(this);
        mes->move(10,170);
        mes->setText("<Font color = #FF0000>ERROR! </Font>");
        mes->show();
    }




}

void PassWord::out()
{
    close();
    emit terminate();
}
