#include <iostream>
#include <cstdlib>

using namespace std;

struct Stu
{
    char name[10];
    int c;
    int m;
    int sum;
};

void COMP(Stu* in[],int n)
{
    Stu* temp;
    int i,j;
    
    n-=1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<(n-i); j++)
        {
            if(in[j]->sum<in[j+1]->sum)
            {
                temp=in[j];
                in[j]=in[j+1];
                in[j+1]=temp;
            }
        }
    }
}

void OUTP(Stu* out[],int m)
{
    int t;
    for(t=0; t<m; t++)
    {
        cout<<out[t]->name<<" "<<out[t]->c<<" "<<out[t]->m<<" "<<out[t]->sum<<" "<<endl;
    }
}

int main()
{
    int N,k,r;
    cin>>N;
    Stu a[N];
    for(k=0; k<N; k++)
    {
        cin>>a[k].name>>a[k].c>>a[k].m;
        a[k].sum=a[k].c+a[k].m;
    }

    struct Stu* pt[N];
    for(r=0; r<N; r++)
    {
        pt[r]=&a[r];
    }

    COMP(pt,N);
    OUTP(pt,N);

    system("pause");
    return 0;
}