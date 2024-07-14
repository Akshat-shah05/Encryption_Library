/* example.c */

#include "arcfour.h"

#define F fflush(stdout)

int main(void);



void printbin(int8 *input, const int16 size) {
    int16 i;
    int8 *p;

    assert(size > 0);

    for (i = size, p = input; i > 0; i--, p++) {
        if (!((i + 1) % 2)) {
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
    int8 *key, *from, *encrypted, *decrypted;

    key="tomatoes"; /* can be from 8 Bits to 2048 Bits */
    skey=strlen(key);
    from="Shall I compare thee to a summer's day";
    stext=strlen(from);

    printf("Initializing encryption algorithm");
    rc4 = rc4init(key, skey);
    printf("done \n");

    printf("'%s'\n ->", from);
    encrypted = rc4encrypt(from, stext);

    printbin(key, skey);

    return 0;

}