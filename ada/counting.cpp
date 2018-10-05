#include<iostream>
using namespace std;

void countingsort(int a[],int b[],int n,int k)
{
	int c[k+1];
	for(int i=0;i<=k;i++)
		c[i]=0;
	for(int i=0;i<n;i++)
		c[a[i]]=c[a[i]]+1;
	for(int i=1;i<=k;i++)
		c[i]=c[i]+c[i-1];
	for(int i=n-1;i>=0;i--)
	{
		b[c[a[i]]-1]=a[i];
		c[a[i]]=c[a[i]]-1;
	}
}

int main()
{
	int n,k;
	cout<<"Enter n = ";
	cin>>n;
	cout<<"Enter maximum number of list = ";
	cin>>k;
	int a[n],b[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	countingsort(a,b,n,k);
	cout<<"Sorted array"<<endl;
	for(int i=0;i<n;i++)
		cout<<b[i]<<"\t";
	cout<<endl;
	return 0;
}
