#include <stdio.h>
#include"hashtable.h"
#define HASH_SIZE 203

unsigned int KRHash(char *s)
{
    unsigned int h = 0, hash_mul = 31;
    while (*s)
        h = h * hash_mul + (unsigned int)*s++;
    return h % HASH_SIZE;
}



int main()
{
    unsigned int h = KRHash("ocelot");
    printf("Hash sum: %d\n", h);
    return 0;
}