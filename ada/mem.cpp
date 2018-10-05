#include<iostream>
#define max1 10
#define max2 50
using namespace std;

int k[max1][max2];
int iter=0;
int maximum(int i,int j)
{
	return i>j?i:j;
}

int mem_knap(int i,int j,int w[],int v[])
{
	iter++;
	int value;
	if(k[i][j]<0)
	{
		if(j<w[i-1])
		{
			value=mem_knap(i-1,j,w,v);
		}
		else
		{
			value=maximum(mem_knap(i-1,j,w,v),v[i-1]+mem_knap(i-1,j-w[i-1],w,v));
		}
		k[i][j]=value;
	}
	return k[i][j];
}

int main()
{
	int n;
	cout<<"Enter no. of items = ";
	cin>>n;
	int w[n],v[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter weight and value = ";
		cin>>w[i]>>v[i];
	}
	int max_w;
	cout<<"Enter knapsack capacity = ";
	cin>>max_w;
	for(int i=0;i<=max_w;i++)
		k[0][i]=0;
	for(int i=0;i<=n;i++)
		k[i][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=max_w;j++)
			k[i][j]=-1;
	cout<<"Total value = "<<mem_knap(n,max_w,w,v)<<endl;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=max_w;j++)
		{
			cout<<k[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"iter = "<<iter<<endl;
	return 0;
}
