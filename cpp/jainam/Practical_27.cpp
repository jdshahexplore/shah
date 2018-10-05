#include<iostream>
using namespace std;

class Person
{
	char name[10];
	public:
		void getdata()
		{
			cout<<"Enter name = ";
			cin>>name;
		}
		void putdata()
		{
			cout<<"Name = "<<name<<endl;
		}
};

int main()
{
	Person *persPtr[10];
	cout<<"Enter data for 10 persons"<<endl<<endl;
	for(int i=0;i<10;i++)
	{
		persPtr[i]=new Person;
		persPtr[i]->getdata();
	}
	cout<<"Details of 10 persons"<<endl<<endl;
	for(int i=0;i<10;i++)
	{
		persPtr[i]->putdata();
		delete persPtr[i];
	}
	
	return 0;
}
