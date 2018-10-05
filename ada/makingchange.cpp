#include<iostream>
using namespace std;

int min(int i,int j)
{
	return i<j?i:j;
}

int makingchange(int d[],int n,int N)
{
	int c[n][N+1];
	for(int i=0;i<n;i++)
	{
		c[i][0]=0;
		for(int j=1;j<=N;j++)
		{
			if(i==0 && j<d[i])
				c[i][j]=999;
			else if(i==0)
				c[i][j]=1+c[i][j-d[i]];
			else if(j<d[i])
				c[i][j]=c[i-1][j];
			else
				c[i][j]=min(c[i-1][j],1+c[i][j-d[i]]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=N;j++)
			cout<<c[i][j]<<"\t";
		cout<<endl;
	}
	return c[n-1][N];
}

int main()
{
	int n,N;
	cout<<"Enter n = ";
	cin>>n;
	int d[n];
	for(int i=0;i<n;i++)
		cin>>d[i];
	cout<<"Enter N = ";
	cin>>N;
	cout<<"Result = "<<makingchange(d,n,N);
}
