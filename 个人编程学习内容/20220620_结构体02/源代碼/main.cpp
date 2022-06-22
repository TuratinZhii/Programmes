#include "alloc.h"
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    char arr[999];
    printf("Please enter a string:\n");
    scanf("%s",arr);

    int check;
    check=strlen(arr);

    //执行分配内存操作
    ALLOC(arr,check);

    return 0;
}