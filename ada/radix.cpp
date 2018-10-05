#include<iostream>
#include<math.h>
#define size 20
using namespace std;

int main()
{
	int n;
	cout<<"Enter n = ";
	cin>>n;
	int a[n],r;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter max digits in numbers = ";
	cin>>r;
	int b[r-1][10];
	radixsort(a,b,n,r-1);
	cout<<"Sorted array"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	cout<<endl;
	return 0;
}
