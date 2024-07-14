/* arcfour.h */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#define rc4decrypt(x, y)   rc4encrypt(x, y)

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

struct s_arcfour {
    //...
    int16 i, j, k;
    int8 s[256];

};

typedef struct s_arcfour Arcfour;

Arcfour *rc4init(int8*, int16);
int8 rc4byte(Arcfour*);
int8 *rc4encrypt(int8*, int16);