/* example.c */

#include "arcfour.h"

#define F fflush(stdout)

int main(void);



void printbin(int8 *input, const int16 size) {
    int16 i;
    int8 *p;

    assert(size > 0);

    for (i = size, p = input; i > 0; i--, p++) {
        if (!((i) % 2)) {
            printf(" ");
        }
        printf("%.02x", *p);
    }

    printf("\n");

    return;
}

int main() {
    Arcfour *rc4;
    int16 skey, stext;
    char *key, *from; 
    int8 *encrypted, *decrypted;

    key=from=0;
    encrypted=decrypted=0;
    from=key;
    skey=stext=0;

    key = "tomatoes"; /* can be from 8 Bits to 2048 Bits */
    skey=strlen(key);
    from = "Shall I compare thee to a summer's day";
    stext=strlen(from);

    printf("\n");
    printf("Initializing encryption ... "); F;
    rc4 = rc4init((int8 *)key, skey);
    printf("done \n");

    printf("'%s'  ->  ", from);
    encrypted = rc4encrypt(rc4, (int8 *)from, stext);
    printbin(encrypted, stext);
    rc4destroy(rc4);

    printf("Running encryption ... "); F;
    rc4 = rc4init((int8 *)key, skey);
    printf("done \n");

    printf("Running decryption ..."); F;
    decrypted = rc4decrypt(rc4, encrypted, stext);
    printf(" -> '%s'\n", decrypted);
    rc4destroy(rc4);
    printf("\n");
    return 0;

}