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
    int ID;

    DataFormat(char* mes);      //retrive data from character//
    DataFormat(){}
    bool validitychar(char* str);  //checks whether string has other than alphabate or not//
    bool validityint(char* str);    //checks whether string is valid integer or not//
    bool check_validity(char* error);   //checks whether data is valid or not//
    bool check_year(int x, int y, int z);   //checks whether year is valid or not//
    bool leap(int x);                       //checks whether year is leap year or not//
    void changetostring(char* message);     //converts data into character//



};

#endif // DATAFORMAT_H
