/* arcfour.h */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

#define export              __attribute__((visibility("default"))) // for exporting the functions to the end users who use the encrypt and init functions
#define rc4decrypt(x, y, z) rc4encrypt(x, y, z)
#define rc4destroy(x)       free(x)

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

struct s_arcfour {
    //...
    int16 i, j, k;
    int8 s[256];

};

typedef struct s_arcfour Arcfour;

export Arcfour *rc4init(int8*, int16);
int8 rc4byte(Arcfour*); // doesn't need to be exported, not used by end user.
export int8 *rc4encrypt(Arcfour*, int8*, int16);