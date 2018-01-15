#include<cstring>
#include "encryption.h"
#include "dataformat.h"
#include <cstring>
using namespace std;


char* encrypt(char *message)
{
        int len = strlen(message);
        int i;
        for(i=0;i<len;i++)
        {
            message[i] = ~message[i];
        }
        return message;
}


char* decrypt(char *message)
{
        int len = strlen(message);
        int i;
        for(i=0;i<len;i++)
        {
            message[i] = ~message[i];
        }

        return message;
}

void encrypt(DataFormat* data)
{

    strcpy(data->name,encrypt(data->name));
    strcpy(data->address,encrypt(data->address));
    strcpy(data->father,encrypt(data->father));
    strcpy(data->mother,encrypt(data->mother));
    strcpy(data->nationality,encrypt(data->nationality));
    data->type = encrypt(data->type);
    strcpy(data->year,encrypt(data->year));
    strcpy(data->month,encrypt(data->month));
    strcpy(data->day,encrypt(data->day));
    data->gender=encrypt(data->gender);
    strcpy(data->passport,encrypt(data->passport));

}
void decrypt(DataFormat* data)
{

    strcpy(data->name,encrypt(data->name));
    strcpy(data->address,encrypt(data->address));
    strcpy(data->father,encrypt(data->father));
    strcpy(data->mother,encrypt(data->mother));
    strcpy(data->nationality,encrypt(data->nationality));
    data->type = encrypt(data->type);
    strcpy(data->year,encrypt(data->year));
    strcpy(data->month,encrypt(data->month));
    strcpy(data->day,encrypt(data->day));
    data->gender=encrypt(data->gender);
    strcpy(data->passport,encrypt(data->passport));
}

char encrypt(char message)
{
   return(~message);
}

char decrypt(char message)
{
   return(~message);
}
