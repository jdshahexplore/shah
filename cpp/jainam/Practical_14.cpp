#include<iostream>
using namespace std;

class time
{
	int hour;
	int min;
	public:
		void setdata() {hour=min=0;}
		void getdata()
		{
			cout<<"Enter hour = ";
			cin>>hour;
			cout<<"Enter minutes = ";
			cin>>min;
		}
		void putdata() {cout<<"Time = "<<hour<<":"<<min<<endl;}
		void addtime(time,time);
		time addtime(time);
};

void time::addtime(time t1,time t2)
{
	min=(t1.min+t2.min)%60;
	hour=t1.hour+t2.hour+(t1.min+t2.min)/60;
}

time time::addtime(time t2)
{
	time t;
	t.min=(min+t2.min)%60;
	t.hour=hour+t2.hour+(min+t2.min)/60;
	return t;
}

int main()
{
	time t1,t2,t3;
	t1.setdata();
	t2.setdata();
	t3.setdata();
	int c;
	cout<<"1: for not returning time object"<<endl;
	cout<<"2: for returning time object"<<endl;
	cout<<"Enter choice = ";
	cin>>c;
	switch(c)
	{
		case 1:
			t1.getdata();
			t2.getdata();
			t3.addtime(t1,t2);
			t3.putdata();
			break;
		case 2:
			t1.getdata();
			t2.getdata();
			t3=t1.addtime(t2);
			t3.putdata();
			break;
		default:
			cout<<"Wrong choice"<<endl;
	}
}
