#include "window.h"
#include "dialog.h"
#include <QLabel>
#include<QPixmap>
#include<QLineEdit>
#include<QPushButton>
#include<fstream>
#include "encryption.h"
#include "dataformat.h"
#include<QDebug>
#include <cstring>
#include <QTcpSocket>
using namespace std;

Window::Window()
{
    setWindowTitle("Client");
    setFixedSize(359,333);

    label = new QLabel(this);
    id = new QLineEdit(this);
    send = new QPushButton(this);
    info1 = new QLabel(this);
    another= new QPushButton(this);
    in = new QRadioButton(this);
    out = new QRadioButton(this);
    post = new QLabel(this);
    clear = new QPushButton(this);


    label->resize(359,333);
    QPixmap map("Files/client.jpg");
    label->setPixmap(map);

    id->move(90,90);
    id->resize(150,25);

    send->setText("Submit");
    send->move(250,90);
    send->resize(75,25);

    info1->move(100,120);
    info1->resize(475,225);
    info1->setText("Welcome.");


    another->setText("Create New Account");
    another->move(100,280);
    another->resize(200,25);

    out->move(170,120);
    in->move(292,120);
    in->setChecked(true);

    clear->setText("Clear");
    clear->move(20,280);
    clear->resize(75,25);

    post->move(200,30);


    connect(another,SIGNAL(clicked(bool)),this,SLOT(is_new()));
    connect(clear,SIGNAL(clicked(bool)),this,SLOT(clear1()));
    connect(send,SIGNAL(clicked(bool)),this,SLOT(submit1()));

}

bool Window::senddata()
{
    QString info;
    QTcpSocket* socket = new QTcpSocket(this);
    socket->connectToHost(ipaddress,2000);

    if(socket->waitForConnected(5000))
    {
        socket->waitForReadyRead();
        info = socket->readAll();

        if(info=="Y")
        {
            socket->flush();
            socket->write("2");
            socket->waitForBytesWritten(1000);

            socket->waitForReadyRead();
            info = socket->readAll();

            if(info == "A")
            {

            socket->flush();
            char message[200];
            data.changetostring(message);
            socket->write(message);
            socket->waitForBytesWritten(1000);

            socket->waitForReadyRead();
            info = socket->readAll();

            if(info.toInt()!=0)
            {
            char mm[40];
            char temp[5];
            strcpy(mm,"Data sent successfully. Your Account ID is : ");
            itoa(info.toInt(),temp,10);
            strcat(mm,temp);
            info1->setText(mm);
            return true;
            }
            else
            {
               return false;
            }


            }
            else{
                return false;
                }


        }
        else{
            return false;
        }


    }
    else{
        return false;
    }



return false;
}



void Window::is_new()
{
    dialog = new Dialog();
    connect(dialog,SIGNAL(data_complete()),this,SLOT(copy()));
    dialog->show();
}

void Window::copy()
{
    data = dialog->data;
    delete dialog;
    char message[200];
    data.changetostring(message);
    if(!senddata())
    {

        info1->setText("Data sending Error!");
    }

}

void Window::changeip(char *ipadd)
{
    strcpy(ipaddress,ipadd);

}

void Window::setpost(char *clnt)
{
    strcpy(client,clnt);
    char temp[50];
    strcpy(temp,"<H1><font color = #FFFFFF>");
    strcat(temp,client);
    strcat(temp,"</font></H1>");
    post->setText(temp);

}

void Window::clear1()
{
    info1->clear();
    id->clear();

}

void Window::submit1()
{
    if((id->text()).toInt()== 0||(id->text()).toInt()>1000)
    {
        info1->setText("Empty ID: Error!!");
        return;
    }
    QString info;
    QTcpSocket* socket = new QTcpSocket(this);
    socket->connectToHost(ipaddress,2000);

    if(socket->waitForConnected(3000))
    {
        socket->waitForReadyRead();
        info = socket->readAll();

        if(info=="Y")
        {
            socket->flush();
            socket->write("3");
            socket->waitForBytesWritten(1000);

            socket->waitForReadyRead();
            info = socket->readAll();

            if(info == "A")
            {

            socket->flush();
            char message[30];
            string t;
            t = (id->text()).toStdString();
            strcpy(message,t.c_str());
            strcat(message,"/");
            strcat(message,client);
            strcat(message,"/");
            if(in->isChecked())
            {
                strcat(message,"IN");
            }
            else
            {
                strcat(message,"OUT");
            }

            socket->flush();
            socket->write(message);
            socket->waitForBytesWritten(1000);

            socket->waitForReadyRead();
            info = socket->readAll();

            if(info == "DONE")
            {
            info1->setText("Data successfully transferred. Thank You!!");
            id->clear();
            }
            else
            {
                if(info=="X")
               info1->setText("Invalid User Id!!!");
                else
               info1->setText("Error occurred while sending data!!!");
            }


            }
            else{
                    info1->setText("Error occurred while sending data!!!");
                }


        }
        else{
            info1->setText("Error occurred while sending data!!!");
        }


    }
    else{
        info1->setText("Error occurred while sending data!!!");
    }


}





