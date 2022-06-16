#include "alloc.h"
#include <cstdio>
#include <cstdlib>

int ALLOC(char input[],int n)
{
    char *pt;
    pt=input;
    //分配给数组

    if(n>200)
    {
        //检查字符串长度是否溢出内存容量
        printf("The string is too long!\n");
        return EXIT_FAILURE;
        //如果溢出，以错误的状态返回
    }
    else
    {
        //如果未溢出，执行分配内存并输出的操作
        #if 0
        malloc(200);
        pt=calloc(40,5);
        #endif

        for(int i=0; i<=n; i++)
        {
            printf("%c",*pt);
            pt++;
        }

        free(pt);
        pt=input;
        return EXIT_SUCCESS;
    }
}
