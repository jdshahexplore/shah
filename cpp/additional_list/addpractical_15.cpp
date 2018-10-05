#include<iostream>
#include<iomanip>
using namespace std;

class Cricket
{
	char p_name[10];
	int runs,innings,Times_not_out;
	float bat_avg;
	public:
	void getdata()
	{
		cout<<"Enter player name = ";
		cin>>p_name;
		cout<<"Enter runs = ";
		cin>>runs;
		cout<<"Enter innings = ";
		cin>>innings;
		cout<<"How many times not out = ";
		cin>>Times_not_out;
		bat_avg = (float)runs/innings;
	}
	void display()
	{
		cout.setf(ios::left, ios::adjustfield);
		cout<<setw(20)<<p_name<<setw(20)<<runs<<setw(20)<<innings<<setw(20)<<Times_not_out<<setw(20)<<bat_avg<<endl;
	}
};

int main()
{
	int n;
	cout<<"Enter number of players = ";
	cin>>n;
	Cricket c[n];
	for(int i=0;i<n;i++)
		c[i].getdata();
	cout.setf(ios::left, ios::adjustfield);
	cout<<endl<<endl<<setw(20)<<"Player's Name"<<setw(20)<<"Runs"<<setw(20)<<"Innings"<<setw(20)<<"Times not out"<<setw(20)<<"Batting_avg"<<endl;
	for(int i=0;i<n;i++)
		c[i].display();
	return 0;
}
