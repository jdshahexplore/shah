#include<iostream>
#define size 10
using namespace std;

int a[2][size],t[2][size];

void assembly(int e[],int x[],int n)
{
	int f0[n],f1[n],l0[n],l1[n],fstar,lstar;
	f0[0]=e[0]+a[0][0];
	f1[0]=e[1]+a[1][0];
	for(int j=1;j<n;j++)
	{
		if((f0[j-1]+a[0][j])<=(f1[j-1]+t[1][j-1]+a[0][j]))
		{
			f0[j]=f0[j-1]+a[0][j];
			l0[j]=0;
		}
		else
		{
			f0[j]=f1[j-1]+t[1][j-1]+a[0][j];
			l0[j]=1;
		}
		if((f1[j-1]+a[1][j])<=(f0[j-1]+t[0][j-1]+a[1][j]))
		{
			f1[j]=f1[j-1]+a[1][j];
			l1[j]=1;
		}
		else
		{
			f1[j]=f0[j-1]+t[0][j-1]+a[1][j];
			l1[j]=0;
		}
	}
	if((f0[n-1]+x[0])<=(f1[n-1]+x[1]))
	{
		fstar=f0[n-1]+x[0];
		lstar=0;
	}
	else
	{
		fstar=f1[n-1]+x[1];
		lstar=1;
	}
	cout<<"Distance = "<<fstar<<endl;
	cout<<"exit line = "<<lstar<<endl;
}

int main()
{
	int n;
	cout<<"Enter no. of activities = ";
	cin>>n;
	int e[2],x[2];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter a[0]["<<i<<"] & a[1]["<<i<<"] = ";
		cin>>a[0][i]>>a[1][i];
	}
	for(int i=0;i<n-1;i++)
	{
		cout<<"Enter t[0]["<<i<<"] && t[1]["<<i<<"] = ";
		cin>>t[0][i]>>t[1][i];
	}
	cout<<"Enter e0 and e1 = ";
	cin>>e[0]>>e[1];
	cout<<"Enter x0 and x1 = ";
	cin>>x[0]>>x[1];
	assembly(e,x,n);
	return 0;
}
