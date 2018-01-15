#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class Dialog1:public QDialog
{
    Q_OBJECT
private:
    QLabel* label1;
    QLabel* label2;
    QPushButton* submit;
    QLineEdit* userid;
    QLineEdit* pass;
    QLabel* warning;

public slots:
    void submitted();
public:
    Dialog1();
};

#endif // DIALOG1_H
