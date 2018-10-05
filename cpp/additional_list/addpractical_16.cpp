#include<iostream>
#include<iomanip>
using namespace std;

class Bill
{
	string name;
	int unit;
	float amount;
	public:
		Bill() {	amount = 50.0;	}
		void get()
		{
			cout<<"Enter name = ";
			cin>>name;
			cout<<"Enter no. of units consumed = ";
			cin>>unit;
		}
		void display()
		{
			cout<<"Name = "<<setw(10)<<name<<endl;
			cout<<"Units = "<<setw(10)<<unit<<endl;
			cout<<"amount = "<<setw(10)<<amount<<endl;
		}
		void amt()
		{
			if(unit<=100)
				amount=amount+unit*0.60;
			else if(unit<=300)
				amount=amount+unit*0.80;
			else
			{
				amount=amount+unit*0.90;
				amount=amount+15*amount/100;
			}
		}
};

int main()
{
	Bill b;
	b.get();
	b.amt();
	b.display();
	return 0;
}
