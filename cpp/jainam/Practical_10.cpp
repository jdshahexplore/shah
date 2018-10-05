#include<iostream>
using namespace std;

class ITEM
{
	int number;
	float cost;
	
	public:
		void getdata()
		{
			cout<<"Enter item number = ";
			cin>>number;
			cout<<"Enter item cost = ";
			cin>>cost;
		}
		
		void setdata()
		{
			number=1;
			cost=100;
		}
		
		void putdata()
		{
			cout<<"Item number = "<<number<<endl;
			cout<<"Item cost = "<<cost<<endl;
		}
};

int main()
{
	ITEM i1;
	cout<<"------Predefined Values------"<<endl;
	i1.setdata();
	i1.putdata();
	cout<<"------Enter New Values------"<<endl;
	i1.getdata();
	cout<<"------New Values------"<<endl;
	i1.putdata();
	return 0;
}
