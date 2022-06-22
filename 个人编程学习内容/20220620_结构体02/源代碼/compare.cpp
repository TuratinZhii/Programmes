#include <cstdio>
#include "student.h"
#include "compare.h"

void COMP(student a[],student b[],int n)
{
    for(int i=0; i<=(n-1); i++) //進行比較
    {
        for(int j=i; j>=0; j--)
        {
            if(a[j+1].sum >= a[j].sum)  //如果滿足條件,則
            {
                int r=j+1;
                b[j]=a[r];
                b[r]=a[j];
            }
        }
    }

    for(int o=0; o<=(n-1); o++) //輸出列表
    {
        printf("%s %d %d %d\n",b[o].name,&b[o].c,&b[o].m,&b[o].sum);
    }
}