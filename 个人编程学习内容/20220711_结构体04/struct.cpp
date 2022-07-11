#include <iostream>
#include <cstdlib>

using namespace std;

struct Rank
{
	int num;
	int det;
};

void COMP(Rank* tmp[],int n);	//�������������������
void OUTP(Rank* out[],int m);	//����źõ����� 
int main()
{
	int N;
	cin>>N;
	
	Rank arr[N];
	
	int k,r;
	for(k=0; k<N; k++)
	{
		cin>>arr[k].num;
		arr[k].det=k+1;
	}
	
	Rank* pt[N];	//ָ�붨�� 
	for(r=0; r<N; r++)
	{
		pt[r]=&arr[r];
	}
	
	COMP(pt,N);
	OUTP(pt,N);
	
	system("pause");
	return 0;
 }
 
void COMP(Rank* tmp[],int n)
{
	Rank* _temp;
	int i,j;
	
	n=n-1;
	for(i=0; i<n; i++)	//ð�ݷ����� 
	{
		for(j=0; j<(n-1); j++)
		{
			if(tmp[j]->num < tmp[j+1]->num)
			{
				_temp=tmp[j];
				tmp[j]=tmp[j+1];
				tmp[j+1]=_temp;
				}	
		}
	}
 }
 
void OUTP(Rank* out[],int m)
{
	int t;
	for(t=0; t<m; t++)
	{
		cout<<out[t]->det<<" ";
	}
 } 
