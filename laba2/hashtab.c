#include<stdio.h>
#include"hashtab.h"

unsigned int hashtab_hash(char *key) {
    unsigned int i = 0;
    for (int j=0; key[j]; j++)
        i += key[j];
    return i % 50000;
}
//hashfun



int main()
{

    return 0;
}