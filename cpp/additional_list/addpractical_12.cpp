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
			cout<<"Enter name of customer = ";
			cin>>name;
			cout<<"Enter your acc_no = ";
			cin>>acc_number;
			cout<<"Enter account_type = ";
			cin>>acc_type;
			cout<<"Enter balance = ";
			cin>>balance;
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
	int ch,n,j;
	float amount;
	cout<<"Enter number of customers = ";
	cin>>n;
	bank p[n];
	cout<<"Enter initial values for all customers"<<endl;
	for(int i=0;i<n;i++)
    {
        cout<<i+1<<"no. customer"<<endl<<endl;
        p[i].setdata();
	}
	read:
	cout<<"------------------------------"<<endl;
    cout<<"1. To deposit an amount"<<endl;
	cout<<"2. To withdraw an amount after checking balance"<<endl;
	cout<<"3. To display name and balance"<<endl;
	cout<<"4. Exit"<<endl;
	cout<<"------------------------------"<<endl;
	cout<<"Enter choice = ";
	cin>>ch;
	switch(ch)
	{
		case 1:
            cout<<"Enter customer_no = ";
            cin>>j;
			cout<<"Enter amount to be deposited = ";
			cin>>amount;
			p[j-1].deposit(amount);
			goto read;
		case 2:
            cout<<"Enter customer_no = ";
            cin>>j;
			cout<<"Enter amount to be Withdrawed = ";
			cin>>amount;
			p[j-1].withdraw(amount);
			goto read;
		case 3:
            cout<<"Enter customer_no = ";
            cin>>j;
			p[j-1].display();
			goto read;
		case 4:
			break;
		default:
			cout<<"Wrong choice"<<endl;
			goto read;
	}
	return 0;
}
