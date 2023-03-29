#include <stdio.h>
#include"hashtable.h"
#define HASHTAB_SIZE 203

unsigned int KRHash(char *s)
{
    unsigned int h = 0, hash_mul = 31;
    while (*s)
        h = h * hash_mul + (unsigned int)*s++;
        //push pointer
    return h % HASHTAB_SIZE;
}

void hashtab_init(struct listnode **hashtab)
{
    int i;
    for (i = 0; i < HASHTAB_SIZE; i++)
        hashtab[i] = NULL;
}






int main()
{
    struct listnode *hashtab[HASHTAB_SIZE];
    unsigned int h = KRHash("ocelot");
    printf("Hash sum: %d\n", h);
    return 0;
}