#include "dialog2.h"
#include<QTextEdit>
#include <QDebug>
#include "values.h"
#include <stdlib.h>
#include "database.h"
#include "dataformat.h"




Dialog2::Dialog2(int i)
{
    space = new QTextEdit(this);
    resize(500,500);
    space->resize(600,500);
    space->show();
if(i==1)
{

    space->append("USER ID\t\tPASSWORD\n");
    int x = databank->getpasslogs();
    char temp[15];
    char temp2[15];

    for(int i=1;i<=x;i++)
    {
        itoa(i,temp,10);
        strcat(temp,"\t\t");
        databank->getpassword(i,temp2);
        if(temp2[0]==NULL)
            continue;
        strcat(temp,temp2);
        strcat(temp,"\n");
        space->append(temp);
    }
}

 if(i==2)
 {
     space->append("USER ID\t\tNAME\n");
     int x = databank->getlogs();
     char temp[15];
     char temp2[15];

     for(int i=1;i<=x;i++)
     {
         itoa(i,temp,10);
         strcat(temp,"\t\t");
         databank->get(DataBase::NAME,temp2,i);
         strcat(temp,temp2);
         strcat(temp,"\n");
         space->append(temp);
     }
 }

 if(i==3)
 {

     space->append("SN.\tID\tActivity\tPost   Time(year,month,day,hour,minute,second)\n");
     int x = databank->getinoutlog();
     char temp[60];

     for(int i=1;i<=x;i++)
     {
         itoa(i,temp,10);
         strcat(temp,".\t");
         logs m;
         databank->retrivelog(m,i);
         strcat(temp,m.ID);
         strcat(temp,"\t");
         strcat(temp,m.inout);
         strcat(temp,"\t");
         strcat(temp,m.post);
         strcat(temp,"\t");
         strcat(temp,m.time);
         strcat(temp,"\n");
         space->append(temp);
     }

 }
}
