#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include "dataformat.h"
using namespace std;

class DataBase
{

private:
    fstream file;


public:
    enum filetype {NAME,ADDRESS,MOTHER,FATHER,NATIONALITY,ACCOUNT,YEAR,MONTH,DAY,GENDER,PASSPORT};

    DataBase();
    void CreateFile(char* str);
    void add(filetype type,char* str, int pos);
    void get(filetype type,char* str,int pos);
    void record(DataFormat data, int num);
    void retrive(DataFormat& data, int x);
    bool checkpassword(int userid, char* password);
    void addpassword(char e[], int pos);
    void getpassword(int pos,char* str);
    void setlogs(int x);
    int getlogs();
    void setpasslogs(int x);
    int getpasslogs();
    void savelog(logs x, int num);
    void retrivelog(logs &x, int num);
    void setinoutlog(int x);
    int getinoutlog();


};

#endif // DATABASE_H
