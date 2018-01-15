#ifndef WINDOW_H
#define WINDOW_H

#include<QMainWindow>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include "dialog.h"
#include "dataformat.h"
#include <QRadioButton>


class Window:public QMainWindow
{
    Q_OBJECT

private:
    QLabel* label;
    QLineEdit* id;
    QPushButton* send;
    QLabel* info1;
    QPushButton* another;
    Dialog* dialog;
    QRadioButton* in;
    QRadioButton* out;
    QLabel* post;
    QPushButton* clear;
    DataFormat data;
    char client[3];
    char ipaddress[20];


public:
    Window(); //This is the constructor that determines how window looks like//
    bool senddata();
public slots:
        void is_new();              //is called when "create new account" is clicked//
        void copy();                   //is called to copy data from dialog box//
        void changeip(char* ipadd);     //called to set ip address//
        void setpost(char* clnt);       //called to set post//
        void clear1();                  //called when clear button is clicked//
        void submit1();                 //called when submit button is clicked//

};

#endif // WINDOW_H
