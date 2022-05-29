#include "reg.h"
#include <iostream>

int REG()
{
    FILE *check;
    check=fopen(".register.txt","rb");
    int inPut,chkOut;
    fscanf(check,"%d",&chkOut);

    std::cout<<"Password:"<<std::endl;
    std::cin>>inPut;

    if(inPut==chkOut)
    {
        return 1;
    }
    else
    {
        std::cout<<"Wrong password!"<<std::endl;
        return REG();
    }
}