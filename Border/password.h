#ifndef PASSWORD_H
#define PASSWORD_H

#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include <QTcpServer>



class PassWord:public QDialog
{
    Q_OBJECT
private:
    QLabel* ip;
    QLabel* username;
    QLabel* password;
    QLineEdit* ip1;
    QLineEdit* username1;
    QLineEdit* password1;
    QPushButton* submitbutton;
    QPushButton* termi;
    QLabel* mes;
public:
    PassWord();

public slots:
        void submit();          //called when submit button is clicked//
        void out();             //called when terminate button is clicked//

signals:
       void terminate();            //emitted when terminate button is clicked//
       void ipchange(char* ipadd);  //emitted to set ip address for program//
       void setpost(char* client);  //emitted to set post for the program//
       void submitted();            //emitted when login complete//

};

#endif // PASSWORD_H
