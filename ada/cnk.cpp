#include<iostream>
using namespace std;

int iter=0;

int min(int i,int k)
{
	return i<=k?i:k;
}

void Compute(int n,int k)
{
	int c[n+1][k+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=min(i,k);j++)
		{
			iter++;
			if(j==0 || i==j)
				c[i][j]=1;
			else
				c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	cout<<"c = "<<c[n][k];
}

int main()
{
	int n,k;
	cout<<"Enter n and k = ";
	cin>>n>>k;
	Compute(n,k);
	cout<<"iter = "<<iter<<endl;
	return 0;
}
