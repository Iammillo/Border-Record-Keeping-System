#include "database.h"
#include "dataformat.h"
#include "myserver.h"
#include <QApplication>
#include "window.h"
#include "encryption.h"
#include "values.h"
#include <QDebug>
DataBase* databank = new DataBase;

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);
    Window* window = new Window();
    window->show();

    MyServer server1(window,2000);

    return(app.exec());

}

