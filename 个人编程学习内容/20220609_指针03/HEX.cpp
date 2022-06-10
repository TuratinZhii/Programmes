#include <cstdio>
#include "HEX.h"

void HEX(char arr_16[],int h)
{
    int rtn_16;
    for(int i = 0; i <= h; i ++)
    {
        rtn_16 = arr_16[i];
        printf("%x",rtn_16);
    }

    return;
}
