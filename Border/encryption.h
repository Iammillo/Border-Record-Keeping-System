#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "dataformat.h"

char* encrypt(char* message);   //encrypts string//
char* decrypt(char* message);   //decrypts string//
char encrypt(char message);     //encrypts character//
char decrypt(char message);     //decrypts character//
void encrypt(DataFormat* data); //encrypts data//
void decrypt(DataFormat* data); //decrypts data//

#endif // ENCRYPTION_H
