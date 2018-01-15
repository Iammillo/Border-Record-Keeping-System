#include<QApplication>
#include "window.h"
#include <QDebug>
#include<QObject>
#include "password.h"
#include "dataformat.h"
using namespace std;

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    PassWord win;
    Window window;
    win.show();

    QObject::connect(&win,SIGNAL(submitted()),&window,SLOT(show()));
    QObject::connect(&win,SIGNAL(terminate()),&window,SLOT(close()));
    QObject::connect(&win,SIGNAL(ipchange(char*)),&window,SLOT(changeip(char*)));
    QObject::connect(&win,SIGNAL(setpost(char*)),&window,SLOT(setpost(char*)));


    app.exec();
    return 0;
}
