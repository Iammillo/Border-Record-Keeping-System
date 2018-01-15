#include "dialog.h"
#include <QLabel>
#include<QPixmap>
#include<QLineEdit>
#include<QPushButton>
#include<QButtonGroup>
#include<QRadioButton>
#include<QWidget>
#include<QString>
#include<string>
#include<cstring>
#include<fstream>
#include<iomanip>
#include "values.h"
using namespace std;

Dialog::Dialog(int x)
{
    num =x;
    setFixedSize(435,538);

    label = new QLabel(this);
    display = new QLabel(this);
    name = new QLineEdit(this);
    address = new QLineEdit(this);
    father = new QLineEdit(this);
    mother = new QLineEdit(this);
    nationality = new QLineEdit(this);
    year = new QLineEdit(this);
    month=new QLineEdit(this);
    day = new QLineEdit(this);
    Passport = new QLineEdit(this);
    male = new QRadioButton(this);
    female = new QRadioButton(this);
    others = new QRadioButton(this);
    native = new QRadioButton(this);
    foreign = new QRadioButton(this);
    submit = new QPushButton(this);
    group1 = new QButtonGroup(this);
    group2 = new QButtonGroup(this);

    QPixmap map("files/reg");
    label->resize(435,538);
    label->setPixmap(map);

    display->move(37,503);
    display->resize(200,25);
    display->setText(" ");

    name->move(151,80);
    name->resize(200,25);

    address->move(151,121);
    address->resize(200,25);

    father -> move(151,196);
    father->resize(200,25);

    mother->move(151,159);
    mother->resize(200,25);

    nationality->move(151,236);
    nationality->resize(200,25);

    year->move(170,332);
    year->resize(50,25);

    month->move(267,332);
    month->resize(30,25);

    day->move(352,332);
    day->resize(30,25);

    Passport->move(151,440);
    Passport->resize(200,25);

    submit->move(351,505);
    submit->setText("Submit");

    male->move(155,388);
    female->move(155,370);
    others->move(155,409);
    native->move(155,276);

    foreign->move(155,296);

    group1->addButton(male);
    group1->addButton(female);
    group1->addButton(others);

    group2->addButton(native);
    group2->addButton(foreign);

    female->setChecked(true);
    native->setChecked(true);

    setModal(true);
    connect(submit,SIGNAL(clicked(bool)),this,SLOT(data_input()));

}

void Dialog::load()
{
    char temp[30];
    databank->get(DataBase::NAME,temp,num);
    name->setText(temp);
    databank->get(DataBase::ADDRESS,temp,num);
    address->setText(temp);
    databank->get(DataBase::FATHER,temp,num);
    father->setText(temp);
    databank->get(DataBase::MOTHER,temp,num);
    mother->setText(temp);
    databank->get(DataBase::NATIONALITY,temp,num);
    nationality->setText(temp);
    databank->get(DataBase::YEAR,temp,num);
    year->setText(temp);
    databank->get(DataBase::MONTH,temp,num);
    month->setText(temp);
    databank->get(DataBase::DAY,temp,num);
    day->setText(temp);
    databank->get(DataBase::PASSPORT,temp,num);
    Passport->setText(temp);
    char ch;
    databank->get(DataBase::GENDER,&ch,num);
    switch(ch)
    {
    case 'M': male->setChecked(true);
                break;
    case 'F':female->setChecked(true);
        break;
    case 'O': others->setChecked(true);
        break;
    }

    databank->get(DataBase::ACCOUNT,&ch,num);
    switch(ch)
    {
    case 'N': native->setChecked(true);
                break;
    case 'F':foreign->setChecked(true);
        break;

    }

}



void Dialog::data_input()
{
    QString milan;
    std::string m;

    milan = name->text();
    m= milan.toStdString();
    strcpy(data.name,m.c_str());


    milan = address->text();
    m= milan.toStdString();
    strcpy(data.address,m.c_str());



    milan = father->text();
    m= milan.toStdString();
    strcpy(data.father,m.c_str());



    milan = mother->text();
    m= milan.toStdString();
    strcpy(data.mother,m.c_str());



    milan = nationality->text();
    m= milan.toStdString();
    strcpy(data.nationality,m.c_str());



    milan = year->text();
    m= milan.toStdString();
    strcpy(data.year,m.c_str());



    milan = month->text();
    m= milan.toStdString();
    strcpy(data.month,m.c_str());



    milan = day->text();
    m= milan.toStdString();
    strcpy(data.day,m.c_str());



    milan = Passport->text();
    m= milan.toStdString();
    strcpy(data.passport,m.c_str());

    if(male->isChecked())
    {
        data.gender = 'M';
    }
    else
        if(female->isChecked())
        {
            data.gender ='F';
        }
    else
        {
            data.gender ='O';
        }

    if(native->isChecked())
    {
        data.type ='N';
    }
    else
        data.type ='F';




    if(data.check_validity(message))
    {

        databank->record(data,num);
        close();
    }
    else
    {
    char message2[50]="<font color = #FF0000>";
    strcat(message2,message);
    strcat(message2,"</font>");
    display->setText(message2);
    }

}
