#include "myserver.h"
#include <QString>
#include <stdio.h>
#include <QDebug>
#include <QTcpSocket>
#include <cstdlib>
#include <database.h>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "values.h"
#include "encryption.h"
#include "dataformat.h"


using namespace std;

MyServer::MyServer(QObject *parent, int port) : QTcpServer(parent)
{
    connect(this,SIGNAL(newConnection()),this,SLOT(goOn()));
 listen(QHostAddress::Any,port);
}

void MyServer::goOn()
{



  QTcpSocket* socket = nextPendingConnection();
  socket->flush();
  socket->write("Y");
  socket->waitForBytesWritten(1000);

  socket->waitForReadyRead();
  str = socket->readAll();

  if(str=="1")
  {

      socket->flush();
      socket->write("A");
      socket->waitForBytesWritten(1000);

      socket->waitForReadyRead();
      str = socket->readAll();
      string a = str.toStdString();
      char x[30];
      strcpy(x, a.c_str());
      char userid[20];
      char password[20];
      int len = strlen(x);
      bool c = false;
      int i,j;
      for(i =0,j=0;i<len;i++,j++)
      {
          if(x[i]=='/')
          {
              c= true;
              j=-1;
              continue;
          }

          if(c==false)
          {
              userid[j]= x[i];
              userid[j+1] = '\0';
          }
          else
          {
              password[j]= x[i];
              password[j+1] = '\0';

          }

      }



      if(databank->checkpassword(atoi(userid),password))
      {
          socket->write("DONE");
          socket->waitForBytesWritten(1000);
      }

      else
      {
          socket->write("Error");
          socket->waitForBytesWritten(1000);


      }


  }
  else
      if(str=="2")
  {
          socket->flush();
          socket->write("A");
          socket->waitForBytesWritten(1000);

          socket->waitForReadyRead();
          str = socket->readAll();
          string a = str.toStdString();
          char x[200];
          strcpy(x, a.c_str());


          DataFormat dat(x);

          int m =databank->getlogs();
          m=m+1;
          databank->record(dat,m);

          databank->setlogs(m);
          char xyz[5];
          itoa(m,xyz,10);
          socket->write(xyz);
          socket->waitForBytesWritten(1000);

  }
  else
      if(str=="3")
      {
          socket->flush();
          socket->write("A");
          socket->waitForBytesWritten(1000);

          socket->waitForReadyRead();
          str = socket->readAll();
          string a = str.toStdString();
          char x[200];
          strcpy(x, a.c_str());

          logs temp;


          int n=0,len,pos=0;
          len = strlen(x);

          for(int i=0;i<len;i++)
          {
              if(x[i]=='/')
              {
                  i++;
                  n++;
                  pos =0;
              }
              switch(n)
              {
              case 0:
                      temp.ID[pos++] = x[i];
                      temp.ID[pos]='\0';
                  break;

              case 1:
                  temp.post[pos++] = x[i];
                  temp.post[pos]='\0';
              break;

              case 2:
                  temp.inout[pos++] = x[i];
                  temp.inout[pos]='\0';
              break;

      }
          }
time_t time1;
time(&time1);
tm* time2;
time2 = localtime(&time1);
char abc[10];
itoa((time2->tm_year)+1900,abc,10);
strcpy(temp.time," ");
strcat(temp.time,abc);
strcat(temp.time,"- ");

itoa((time2->tm_mon)+1,abc,10);
strcat(temp.time,abc);
strcat(temp.time,"- ");

itoa(time2->tm_mday,abc,10);
strcat(temp.time,abc);
strcat(temp.time,"- ");

itoa(time2->tm_hour,abc,10);
strcat(temp.time,abc);
strcat(temp.time,":");

itoa(time2->tm_min,abc,10);
strcat(temp.time,abc);
strcat(temp.time,":");

sprintf(abc,"%d",time2->tm_sec);
strcat(temp.time,abc);
if((atoi(temp.ID))<=(databank->getlogs()))
{
databank->savelog(temp,(databank->getinoutlog())+1);
databank->setinoutlog(1+databank->getinoutlog());
socket->write("DONE");
socket->waitForBytesWritten(1000);
}
else
{
    socket->write("X");
    socket->waitForBytesWritten(1000);
      }
  socket->close();
}
}

