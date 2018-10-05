#include<iostream>
using namespace std;

int n;

void merge(int a[],int low,int mid,int high)
{
	int i=low,j=mid+1;
	int k=low;
	int temp[n];
	while(i<=mid && j<=high)
	{
		if(a[i]<=a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=high)
		temp[k++]=a[j++];
	for(int i=low;i<=high;i++)
		a[i]=temp[i];
}

void merge_sort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

int main()
{
	cout<<"Enter n = ";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	merge_sort(a,0,n-1);
	cout<<"Sorted array"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	return 0;
}
