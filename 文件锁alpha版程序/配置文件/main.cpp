#include "rev.h"
#include "crt.h"
#include <iostream>
using namespace std;

int main()
{
    FILE *rights;
    rights=fopen(".rights.txt","rb");
    char R[99];
    fgets(R,99,rights);
    fputs(R,stdout);

    std::cout<<"\nPress 1 to register your password;press 2 to edit your file."<<std::endl;
    int ch;
    std::cin>>ch;

    if(ch==1)
        REV();
    if(ch==2)
        CRT();

    return 0;
}