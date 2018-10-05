#include<iostream>
using namespace std;

void sort(int a[],int n)
{
	int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

int main()
{
	int n;
	cout<<"Enter size of array = ";
	cin>>n;
	int a[n];
	cout<<"Enter elements of array"<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];

	sort(a,n);

	cout<<"Sorted Array"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	return 0;
}
