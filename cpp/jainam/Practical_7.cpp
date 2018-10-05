#include<iostream>
using namespace std;

void swap(int a,int b)
{
	int c=a;
	a=b;
	b=c;
	cout<<"a = "<<a<<" b = "<<b<<endl<<endl;
}

void swap(int *a,int *b)
{
	int c=*a;
	*a=*b;
	*b=c;
}

int main()
{
	int ch;
	cout<<"1: Call By Value"<<endl;
	cout<<"2: Call By Reference"<<endl;
	cout<<"3: Exit"<<endl;
	read:
	cout<<"Enter Choice = ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			int a,b;
			cout<<"enter two numbers = ";
			cin>>a>>b;
			swap(a,b);
			goto read;
		case 2:
			cout<<"enter two numbers = ";
			cin>>a>>b;
			swap(&a,&b);
			cout<<"a = "<<a<<" b = "<<b<<endl<<endl;
			goto read;
		case 3:
			break;
		default:
			cout<<"wrong choice"<<endl<<endl;
			goto read;
	}
	return 0;
}
