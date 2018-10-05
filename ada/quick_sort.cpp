#include<iostream>
using namespace std;

int partition(int a[],int low,int high)
{
	int pivot=a[low];
	int i=low+1,j=high,temp;
	while(i<=j)
	{
		while(a[i]<=pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}			
	}
	temp=a[low];
	a[low]=a[j];
	a[j]=temp;
	return j;
}

void quicksort(int a[],int low,int high)
{
	if(low<high)
	{
		int m=partition(a,low,high);
		quicksort(a,low,m-1);
		quicksort(a,m+1,high);
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
	quicksort(a,0,n-1);
	cout<<"Sorted Elements"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	return 0;
}
