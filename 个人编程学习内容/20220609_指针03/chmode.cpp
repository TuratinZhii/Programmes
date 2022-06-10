#include <cstdio>
#include <cstring>
#include "DEC.h"
#include "HEX.h"
#include "OCT.h"

using namespace std;

int main()
{
    char input[99];
    printf("Please input the sentence:(type space to end)\n");
    scanf("%s",&input);
    int len;

    //检测字符数组长度
    len = strlen(input);

    int check;
    printf("Please choose the output mode:\n 1.dec; 2.hex; 3.oct.\n");
    scanf("%d",&check);

    void (*func)(char arr[],int t);
    long long output;
    if(check == 1)
        func = DEC;
    if(check == 2)
        func = HEX;
    if(check == 3)
        func = OCT;

    (*func)(input,len);

    return 0;
}
