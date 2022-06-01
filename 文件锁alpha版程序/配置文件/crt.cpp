#include "crt.h"
#include "reg.h"
#include "stdio.h"
#include <stdlib.h>

//文件修改模块
void edit();
void CRT()
{
    FILE *read,*write;
    read=fopen(".file.txt","rb");
    write=fopen(".file.txt","wb");

    int c;
    c=REG();
    if(c==1)
    {
        printf("\n");
        char wrt;
        while(fscanf(read,"%c",&wrt)==1)
            printf("%c",wrt);
        printf("\n");
        printf("Press 1 to edit,Press enter to save.\n");
        
        int u;
        scanf("%d",&u);
        if(u==1)
            edit();
    }
}

void edit()
{
    FILE *wrtin;
    wrtin=fopen(".file.txt","wb");
    char Wrt[9999];

    fgets(Wrt,9999,stdin);
    fputs(Wrt,wrtin);
    printf("Saved!");
    system("pause");
}