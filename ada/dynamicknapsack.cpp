#include<iostream>
using namespace std;

int maximum(int i,int j)
{
	return i>j?i:j;
}

int knapsack(int w[],int v[],int n,int max_w)
{
	int k[n+1][max_w+1];
	for(int i=0;i<=max_w;i++)
		k[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		k[i][0]=0;
		for(int j=1;j<=max_w;j++)
		{
			if(j<w[i-1])
				k[i][j]=k[i-1][j];
			else
				k[i][j]=maximum(k[i-1][j],v[i-1]+k[i-1][j-w[i-1]]);
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=max_w;j++)
		{
			cout<<k[i][j]<<"\t";
		}
		cout<<endl;
	}
	return k[n][max_w];
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
	cout<<"Total value = "<<knapsack(w,v,n,max_w);
	return 0;
}
