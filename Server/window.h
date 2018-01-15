#ifndef WINDOW_H
#define WINDOW_H

#include<QMainWindow>
#include<QPushButton>
#include <QLabel>
#include "dialog1.h"
#include "dialog2.h"
#include "dialog.h"
#include <QLineEdit>


class Window:public QMainWindow
{
    Q_OBJECT
private:
    QPushButton* setpass;
    QPushButton* seeall;
    QPushButton* seepersonal;
    QPushButton* allperson;
    QPushButton* allpass;
    QLabel* background;
    Dialog1* dialog;
    Dialog2* dialog2;
    QLineEdit* edit;
    QLabel* idlabel;
    Dialog* dia;




public:
    Window();

public slots:
    void on_pass_change();
    void allpassword();
    void allaccount();
    void personal();
    void logs();
};

#endif // WINDOW_H
