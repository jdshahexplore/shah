#include<iostream>
using namespace std;
int a=10;

int main()
{
	int a=20;
	cout<<"We are in main function"<<endl;
	cout<<"a = "<<a<<endl;
	cout<<"::a = "<<::a<<endl;
	{
		int a=30;
		cout<<"We are in inner block"<<endl;
		cout<<"a = "<<a<<endl;
		cout<<"::a = "<<::a<<endl;
	}
	return 0;
}
