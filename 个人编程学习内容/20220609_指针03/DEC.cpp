#include <cstdio>
#include "DEC.h"

void DEC(char arr_10[],int d)
{
    int rtn_10;
    for(int i = 0; i <= d; i ++)
    {
        rtn_10 = arr_10[i];
        printf("%d",rtn_10);
    }

    return;
}
