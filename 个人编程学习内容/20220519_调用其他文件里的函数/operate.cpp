#include"stdio.h"
using namespace std;
char str[999];
int main()
{
    extern void INPUT_STRING(char str[]);   //输入函数
    extern void DELETE_STRING(char str[],char ch);  //操作函数
    extern void OUTPUT_STRING(char str[]);  //输出函数

    char c;

    INPUT_STRING(str);
    printf("请输入要删去的字符：");
    scanf("%c",&c);
    DELETE_STRING(str,c);
    OUTPUT_STRING(str);

    return 0;
}