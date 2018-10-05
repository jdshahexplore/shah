#include<iostream>
using namespace std;

template<class T>
void bubble_sort(T b[])
{
	T temp;
	for(int i=0;i<10;i++)
		for(int j=i;j<10;j++)
			if(b[i]>b[j])
			{
				swap(b[i],b[j]);
			}
}

template<class T1>
void swap(T1 a,T1 b)
{
	T1 temp;
	temp=a;
	a=b;
	b=temp;
}

int main()
{
	int a[5];
	float b[10];
	cout<<"Enter 5 integer elements"<<endl;
	for(int i=0;i<5;i++)
		cin>>a[i];
	cout<<"Enter 5 float elements"<<endl;
	for(int i=0;i<5;i++)
		cin>>b[i];
	for(int i=0;i<5;i++)
	{
		b[i+5]=b[i];
		b[i]=a[i];
	}
	bubble_sort<float>(b);
	cout<<endl<<"---------Sorted Array---------"<<endl;
	for(int i=0;i<10;i++)
		cout<<b[i]<<endl;
	return 0;
}
