#include "database.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <QDebug>
#include "dataformat.h"
#include "encryption.h"
#include "values.h"

using namespace std;


/*
 * constrctor of database
 * initialize all file required to set database
 */
DataBase::DataBase()
{
    CreateFile("data/file1.txt");
    CreateFile("data/file2.txt");
    CreateFile("data/file3.txt");
    CreateFile("data/file4.txt");


   }

/*
 * Function to create file if not present
 */
void DataBase::CreateFile(char* str)
{
   ifstream x(str);

   if(!x)
   {
       x.close();
       file.open(str,ios::out);
       file.seekp(1);
       int num=0;
       file<<num;
       file.seekp(10);
       file<<num;
       file.seekp(15);
       file<<num;
       file.close();
   }
   else
   {
       x.close();
   }
}



void DataBase::add(DataBase::filetype type, char *e, int pos)
{
    file.open("data/file1.txt");
    DataFormat data;
    file.seekg(pos*sizeof(data));
    file.read(reinterpret_cast<char*>(&data),sizeof(data));

    if(type == GENDER||type == ACCOUNT)
    {       if(type==ACCOUNT)
        {
            data.type = *e;
          }
        else
        {

             data.gender = *e;

        }


    }
    else
    {

    switch(type)
    {
    case NAME:
        strcpy(data.name,e);
        break;
    case ADDRESS:
        strcpy(data.address,e);
        break;

    case MOTHER:
        strcpy(data.mother,e);
        break;
    case FATHER:
       strcpy(data.father,e);
        break;
    case NATIONALITY:
        strcpy(data.nationality,e);
        break;

    case YEAR:
        strcpy(data.year,e);
        break;
    case MONTH:
        strcpy(data.month,e);
        break;
    case DAY:
        strcpy(data.day,e);
        break;

    case PASSPORT:
        strcpy(data.passport,e);
        break;
    }
    }
record(data,pos);
file.close();
}

void DataBase::get(DataBase::filetype type, char *str, int pos)
{


    DataFormat data;
    databank->retrive(data,pos);

    if(type == GENDER||type == ACCOUNT)
    {       if(type==ACCOUNT)
        {
            *str = data.type;
          }
        else
        {

            *str= data.gender;

        }


    }
    else
    {

    switch(type)
    {
    case NAME:
        strcpy(str,data.name);
        break;
    case ADDRESS:
        strcpy(str,data.address);
        break;

    case MOTHER:
        strcpy(str,data.mother);
        break;
    case FATHER:
       strcpy(str,data.father);
        break;
    case NATIONALITY:
        strcpy(str,data.nationality);
        break;

    case YEAR:
        strcpy(str,data.year);
        break;
    case MONTH:
        strcpy(str,data.month);
        break;
    case DAY:
        strcpy(str,data.day);
        break;

    case PASSPORT:
        strcpy(str,data.passport);
        break;

    }
file.close();
}

}
void DataBase::record(DataFormat data, int num)
{
    file.open("data/file1.txt");
   encrypt(&data);
    char temp[200];
    data.changetostring(temp);
    int len = strlen(temp);

        char str[len+2];
        sprintf(str,"%c",len);
        strcat(str,temp);
        file.seekp(num*(sizeof(data)));
        file.write(str,strlen(str));
    file.close();

}

void DataBase::retrive(DataFormat &data, int x)
{

    file.open("data/file1.txt");
    char ch;
    char temp[200];
    file.seekg(x*(sizeof(data)));
    file.get(ch);
    file.read(temp,int(ch));
    temp[int(ch)]='\0';
    file.close();
    data = DataFormat(temp);
    decrypt(&data);


}

bool DataBase::checkpassword(int userid, char *password)
{
    char temp[12];
    databank->getpassword(userid,temp);
    if(strcmp(password,temp)==0)
    {
        return true;
    }
    else return false;

}

void DataBase::addpassword(char e[], int pos)
{
    char a[20];
    strcpy(a,e);
    encrypt(a);
    int len = strlen(a);
        char str[len+2];
        sprintf(str,"%c",len);
        strcat(str,a);

        file.open("data/file2.txt");
        file.seekp(pos*12);
        file.write(str,strlen(str));
        file.close();

}


void DataBase::getpassword(int pos,char* str)
{

           file.open("data/file2.txt");
            file.seekg(pos*12);
            char x;
            file.get(x);
            char temp[20];
            file.read(temp,int(x));
            decrypt(temp);
            temp[int(x)]='\0';
            strcpy(str,temp);
            file.close();

}

void DataBase::setlogs(int x)
{
    file.open("data/file4.txt");
    file.seekp(1);
    file<<x;
    file.close();

}

int DataBase::getlogs()
{
    file.open("data/file4.txt");
    file.seekg(1);
    int num;
    file>>num;
    file.close();
    return num;
}

void DataBase::setpasslogs(int x)
{
    file.open("data/file4.txt");
    file.seekp(10);
    file<<x;
    file.close();

}

int DataBase::getpasslogs()
{
    file.open("data/file4.txt");
    file.seekg(10);
    int num;
    file>>num;
    file.close();
    return num;
}

void DataBase::savelog(logs x,int num)
{
    qDebug()<<x.time;
    file.open("data/file3.txt");
    char temp[50];
    strcpy(temp,x.ID);
    strcat(temp,"/");
    strcat(temp,x.inout);
    strcat(temp,"/");
    strcat(temp,x.post);
    strcat(temp,"/");
    strcat(temp,x.time);
    strcat(temp,"/");

    encrypt(temp);
    int len = strlen(temp);

        char str[len+2];
        sprintf(str,"%c",len);

        strcat(str,temp);
        file.seekp(num*50);
        file.write(str,strlen(str));

     file.close();

}

void DataBase::retrivelog(logs &x, int num)
{

    file.open("data/file3.txt");


     file.seekg(num*50 );
    char x1;
     file.get(x1);




     char temp[50];
     file.seekg(num*50+1);
     file.read(temp,int(x1));
     temp[int(x1)]='\0';
     decrypt(temp);
     file.close();


     int n=0,len,pos=0;
     len = strlen(temp);

     for(int i=0;i<len;i++)
     {
         if(temp[i]=='/')
         {
             i++;
             n++;
             pos =0;
         }
         switch(n)
         {
         case 0:
                 x.ID[pos++] = temp[i];
                 x.ID[pos]='\0';
             break;

         case 1:
             x.inout[pos++] = temp[i];
             x.inout[pos]='\0';
         break;

         case 2:
             x.post[pos++] = temp[i];
             x.post[pos]='\0';

         break;
         case 3:
             x.time[pos++] = temp[i];
             x.time[pos]='\0';
             break;
         case 4:
             break;

 }
     }


}

void DataBase::setinoutlog(int x)
{
    file.open("data/file4.txt");
    file.seekp(15);
    file<<x;
    file.close();

}

int DataBase::getinoutlog()
{
    file.open("data/file4.txt");
    file.seekg(15);
    int num;
    file>>num;
    file.close();
    return num;
}

