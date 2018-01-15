#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "dataformat.h"

char* encrypt(char* message);
char* decrypt(char* message);
char encrypt(char message);
char decrypt(char message);
void encrypt(DataFormat* data);
void decrypt(DataFormat* data);

#endif // ENCRYPTION_H
