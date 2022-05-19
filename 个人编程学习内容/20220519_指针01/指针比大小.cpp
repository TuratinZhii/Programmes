#include"stdio.h"
using namespace std;

void SWAP(int *p1,int *p2);

int main(){

    int a,b;
    int *pt1,*pt2;

    printf("请分别输入两个值：\n");
    scanf("%d %d",&a,&b);
    
    pt1=&a;
    pt2=&b;
    if (a<b)
        SWAP(pt1,pt2);
    
    printf("The bigger one is:\n %d %d",a,b);
    return 0;
}

void SWAP(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}