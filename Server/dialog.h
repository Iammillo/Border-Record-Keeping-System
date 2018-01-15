#ifndef DIALOG_H
#define DIALOG_H

#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QRadioButton>
#include<QButtonGroup>
#include "dataformat.h"


class Dialog:public QDialog
{
    Q_OBJECT

private:
    QLabel* label;
    QLineEdit* name;
    QLineEdit* address;
    QLineEdit* father;
    QLineEdit* mother;
    QLineEdit* nationality;
    QLineEdit* year;
    QLineEdit* month;
    QLineEdit* day;
    QLineEdit* Passport;
    QRadioButton* male;
    QRadioButton* female;
    QRadioButton* others;
    QRadioButton* native;
    QRadioButton* foreign;
    QPushButton* submit;
    QButtonGroup* group1;
    QButtonGroup* group2;
    QLabel* display;
    char message[50];
    int num;


public:
    DataFormat data;
    Dialog(int x);
    void load();

public slots:
    void data_input();

signals:


};

#endif // DIALOG_H
