#include "rev.h"
#include "reg.h"
#include <iostream>
#include <stdlib.h>

//密码修改模块
void crt();
void REV()
{
    int c;
    c=REG();

    if(c==1)
        crt();
    else
        REV();
}

void crt()
{
    FILE *rewrite;
    rewrite=fopen(".register.txt","wb");

    int f,s;
    std::cout<<"New password:"<<std::endl;
    std::cin>>f;
    std::cout<<"Again:"<<std::endl;
    std::cin>>s;

    if(f==s)
    {
        fprintf(rewrite,"%d",f);
        std::cout<<"Saved!"<<std::endl;
        system("pause");
    }
    else
    {
        std::cout<<"Not the same!"<<std::endl;
        crt();
    }
}