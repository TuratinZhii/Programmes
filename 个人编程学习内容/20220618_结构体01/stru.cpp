#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N); //输入整数N
    N+=1;

    struct STUDENT
    {
        char name[10];  //姓名
        int c;  //语文分数
        int m;  //数学分数
        int sum;    //总分
    }
    stu[N],temp[1];

    scanf("%s %d %d",stu[0].name,&stu[0].c,&stu[0].m);  //输入数组的首个元素

    for(int i=1; i<=N; i++)
    {
        scanf("%s %d %d",stu[i].name,&stu[i].c,&stu[i].m);
        stu[i].sum=stu[i].c+stu[i].m;
        if(stu[i].sum>=stu[i-1].sum)    //比较总分数
        {
            for(int a=0; a<=10; a++)
                temp[1].name[a]=stu[i].name[a];

            temp[1].c=stu[i].c;
            temp[1].m=stu[i].m;
            temp[1].sum=stu[i].sum;

            for(int b=0; b<=10; b++)
                stu[i].name[b]=stu[i-1].name[b];

            stu[i].c=stu[i-1].c;
            stu[i].m=stu[i-1].m;
            stu[i].sum=stu[i-1].sum;

            for(int c=0; c<=10; c++)
                stu[i-1].name[c]=temp[1].name[c];

            stu[i-1].c=temp[1].c;
            stu[i-1].m=temp[1].m;   
            stu[i-1].sum=temp[1].sum;   //将两个元素的成员互换
        }
    }

    for(int j=0; j<=N; j++)
    {
        printf("%s %d %d %d",stu[j].name,stu[j].c,stu[j].m,stu[j].sum);
    }

    system("pause");
    return 0;
}
