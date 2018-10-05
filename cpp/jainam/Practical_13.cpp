#include<iostream>
#include<string.h>
using namespace std;

class EMPLOYEE
{
	string name;
	int age;
	
	public:
	void getdata()
	{
		cout<<"Enter name = ";
		cin>>name;
		cout<<"Enter age = ";
		cin>>age;
	}
	
	void putdata()
	{
		cout<<"Name = "<<name<<endl;
		cout<<"Age = "<<age<<endl;
	}
};

int main()
{
	int n;
	cout<<"Enter number of employee = ";
	cin>>n;
	EMPLOYEE e[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter details of Employee "<<i+1<<endl;
		e[i].getdata();
	}
	for(int i=0;i<n;i++)
	{
		cout<<"Details of Employee "<<i+1<<endl;
		e[i].putdata();
	}
}
