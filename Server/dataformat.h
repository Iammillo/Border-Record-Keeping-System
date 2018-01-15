#ifndef DATAFORMAT_H
#define DATAFORMAT_H

#include<cstring>
#include<cstdlib>
class DataFormat
{
public:
    char name[30];
    char address[30];
    char father[30];
    char mother[30];
    char nationality[20];
    char type;
    char year[5];
    char month[3];
    char day[3];
    char gender;
    char passport[12];


    DataFormat(char* mes);
    DataFormat(){}
    bool validitychar(char* str);
    bool validityint(char* str);
    bool check_validity(char* error);
    bool check_year(int x, int y, int z);
    bool leap(int x);
    void changetostring(char* message);



};

struct logs
{
    char post[5];
    char ID [5];
    char inout[5];
    char time[40];
};


#endif // DATAFORMAT_H
