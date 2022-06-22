#include <cstdio>
#include <cstdlib>
#include "student.h"
#include "compare.h"

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);

    student line_1[N],line_2[N];    //姓名列表

    for(int t=0; t<=(N-1); t++) //輸入各成員的值
    {
        scanf("%s %d %d",line_1[t].name,&line_1[t].c,&line_1[t].m);
        line_1[t].sum=line_1[t].c+line_1[t].m;
    }

    COMP(line_1,line_2,N);

    system("pause");
    return 0;
}
