#include "window.h"
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include "dialog1.h"
#include<fstream>
#include "values.h"
#include <QLineEdit>
#include "dialog2.h"

using namespace std;

Window::Window()
{
    setWindowTitle("SERVER!!");
    setFixedSize(400,320);
    QPixmap map("files/server1.jpg");
    background = new QLabel(this);
    background->resize(400,320);
    background->move(0,0);
    background->setPixmap(map);

    setpass = new QPushButton(this);
    setpass->move(25,110);
    setpass->setText("Set Password");

    seeall = new QPushButton(this);
    seeall->move(25,150);
    seeall->setText("See all Logs");

    seepersonal = new QPushButton(this);
    seepersonal->move(25,190);
    seepersonal->setText("See Personal Info");

    allperson = new QPushButton(this);
    allperson->move(25,230);
    allperson->setText("See All Person");

    allpass = new QPushButton(this);
    allpass->move(25,270);
    allpass->setText("See All Passwords.");


    idlabel = new QLabel(this);
    idlabel->setText("ID:");
    idlabel->move(150,190);

    edit = new QLineEdit(this);
    edit->move(200,190);

    connect(setpass,SIGNAL(clicked(bool)),this,SLOT(on_pass_change()));
    connect(allpass,SIGNAL(clicked(bool)),this,SLOT(allpassword()));
    connect(allperson,SIGNAL(clicked(bool)),this,SLOT(allaccount()));
    connect(seepersonal,SIGNAL(clicked(bool)),this,SLOT(personal()));
    connect(seeall,SIGNAL(clicked(bool)),this,SLOT(logs()));
}

void Window::on_pass_change()
{

    dialog= new Dialog1;
    dialog->show();


}

void Window::allpassword()
{

  dialog2 = new Dialog2(1);
  dialog2->show();
}

void Window::allaccount()
{
    dialog2 = new Dialog2(2);
    dialog2->show();
}

void Window::personal()
{
    int i = (edit->text()).toInt();
    int m = databank->getlogs();
    if(i!=0&&i<=m&&i>0)
    {
    dia = new Dialog(i);
    dia->load();
    dia->show();
}

}

void Window::logs()
{
    dialog2 = new Dialog2(3);
    dialog2->show();

}
