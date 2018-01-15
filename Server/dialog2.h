#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include <QTextEdit>

class Dialog2:public QDialog
{
    Q_OBJECT
private:
    QTextEdit* space;

public:
    Dialog2(int i);
};
#endif // DIALOG2_H
