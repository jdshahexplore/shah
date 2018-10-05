#include<iostream>
#define size 20
using namespace std;

int max=0,min=0;
int a[size];

void max_min(int i,int j)
{
	int max1,min1;
	if(i==j)
	{
		max=min=a[j];
	}
	else if(i=j-1)
	{
		if(a[i]<a[j])
		{
			max=a[j];
			min=a[i];
		}
		else
		{
			max=a[i];
			min=a[j];
		}
	}
	else
	{
		int mid=(i+j)/2;
		max_min(i,mid);
		max1=max;
		min1=min;
		max_min(mid+1,j);
		if(max<max2)
			max=max2;
		if(min>min2)
			min=min2;
	}
}

int main()
{
	int n;
	cout<<"Enter n = ";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	max_min(0,n-1);
	cout<<"max = "<<max<<endl;
	cout<<"min = "<<min<<endl;
	return 0;
}
