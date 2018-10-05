#include<iostream>
#include<string.h>
using namespace std;

class bank
{
	string name;
	int acc_number;
	string acc_type;
	float balance;

	public:
		void setdata()
		{
			name="jainam";
			acc_number=101;
			acc_type="Saving";
			balance=1000;
		}

		void deposit(float amount)
		{
			balance=balance+amount;
		}

		void withdraw(float amount)
		{
			if(balance>amount)
			{
				balance=balance-amount;
				cout<<"Your withdrawal of amount = "<<amount<<" is successful"<<endl;
			}
			else
				cout<<"Balance is less than requested amount\nWithdrawal unsuccessful"<<endl;
		}

		void display()
		{
			cout<<"Name = "<<name<<endl;
			cout<<"Balance = "<<balance<<endl;
		}
};

int main()
{
	int ch;
	float amount;
	bank p1;
	p1.setdata();
	cout<<"1. To deposit an amount"<<endl;
	cout<<"2. To withdraw an amount after checking balance"<<endl;
	cout<<"3. To display name and balance"<<endl;
	cout<<"4. Exit"<<endl;
	read:
	cout<<"Enter choice = ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Enter amount to be deposited = ";
			cin>>amount;
			p1.deposit(amount);
			goto read;
		case 2:
			cout<<"Enter amount to be Withdrawed = ";
			cin>>amount;
			p1.withdraw(amount);
			goto read;
		case 3:
			p1.display();
			goto read;
		case 4:
			break;
		default:
			cout<<"Wrong choice"<<endl;
			goto read;
	}
	return 0;
}
