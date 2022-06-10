#include <cstdio>
#include "OCT.h"

void OCT(char arr_8[],int o)
{
    int rtn_8;
    for(int i = 0; i <= o; i ++)
    {
        rtn_8 = arr_8[i];
        printf("%o",rtn_8);
    }

    return;
}
