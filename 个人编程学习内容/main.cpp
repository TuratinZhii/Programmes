#include<iostream>
#include"factorial.h"
using namespace std;
int main(){
    int inPut;
    FTR imple;
    std::cout<<"请输入阶乘次数：\n"<<endl;
    std::cin>>inPut;
    std::cout<<imple.ftr(inPut)<<std::endl;
    return 0;
}