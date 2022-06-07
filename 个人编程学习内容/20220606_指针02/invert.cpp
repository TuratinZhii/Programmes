#include "stdio.h"
#include <cstring>

using namespace std;

int main()
{
    char arr_1[9999];
    char *p_1;
    p_1=arr_1;

    FILE *fo;
    fo=fopen("read.txt","rb");

    printf("The original sentence is:\n");
    for(int i=0; i<=10000; i++,p_1++)
    {
        fscanf(fo,"%c",p_1);    //这里的"p_1"相当于"&arr[]"。
    }
    fputs(arr_1,stdout);
    printf("\n");

    int a;
    a=strlen(arr_1);

    printf("The sentence has been inverted:\n");
    for(p_1=arr_1+a; p_1>=arr_1; p_1--)
        printf("%c",*p_1);  //这里的"*p_1"相当于"arr[]"，注意与上边的区别。

    return 0;
}
