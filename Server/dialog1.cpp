#include "dialog1.h"
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <cstring>
#include "database.h"
#include<QObject>
#include "values.h"
#include "dataformat.h"
using namespace std;


void Dialog1::submitted()
{
    char passwrd[20];
    strcpy(passwrd,((pass->text()).toStdString()).c_str());
    int uid =0;
    uid= (userid->text()).toInt();
    if(uid==0||uid<0)
    {
        warning->setText("Invalid!!");
        return;

    }
    databank->addpassword(passwrd,uid);
    int x = databank->getpasslogs();
    if(x<uid)
    {
        databank->setpasslogs(uid);
    }
    this->close();



}

Dialog1::Dialog1()
{
    setWindowTitle("P.W change");
    resize(200,100);

    label1 = new QLabel(this);
    label2 = new QLabel(this);

    userid = new QLineEdit(this);
    pass = new QLineEdit(this);
    submit = new QPushButton(this);

    setModal(true);

    label1->move(10,10);
    label1->setText("UserId:");

    label2->move(10,40);
    label2->setText("Password");

    userid->move(60,10);
    pass->move(60,40);

    submit->move(10,70);
    submit->setText("Change Password");

    warning= new QLabel(this);
    warning->move(120,70);
    warning->setText("Update P.W");

    connect(submit,SIGNAL(clicked(bool)),this,SLOT(submitted()));

}



