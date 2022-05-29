#include "crt.h"
#include "reg.h"
#include "stdio.h"
#include <stdlib.h>

//文档修改模块
void fileop();
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
        printf("Press 1 to edit,press enter to save.");
        
        int u;
        scanf("%d",&u);

        if(u==1)
        {
            fileop();
        }
    }
}

void fileop()
{
    FILE *wrtin;
    wrtin=fopen(".file.txt","wb");
    char Wrt[9999];

    fgets(Wrt,9999,stdin);
    fputs(Wrt,wrtin);
    printf("Saved!");
    system("pause");
}