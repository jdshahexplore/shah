#include<iostream>
using namespace std;

class Distance
{
	int feet,inches;
	public:
		void setdist()
		{
			feet=inches=0;
		}
		void getdist()
		{
			cout<<"Enter feet : ";
			cin>>feet;
			cout<<"Enter inches : ";
			cin>>inches;
		}
		void showdist()
		{
			cout<<"------------"<<endl<<feet<<"'-"<<inches<<"\""<<endl<<"------------"<<endl;
		}
		void add_dist(Distance,Distance);
		Distance add_dist(Distance);
};

void Distance::add_dist(Distance d1,Distance d2)
{
	inches=(d1.inches+d2.inches)%12;
	feet=d1.feet+d2.feet+(d1.inches+d2.inches)/12;
}

Distance Distance::add_dist(Distance d2)
{
	Distance d;
	d.inches=(inches+d2.inches)%12;
	d.feet=feet+d2.feet+(inches+d2.inches)/12;
	return d;
}

int main()
{
	Distance d1,d2,d3;
	int c;
	d1.setdist();
	d2.setdist();
	d3.setdist();
	cout<<"1: add distance by method1\n2: add distance by method2"<<endl;
	cout<<"Enter choice : ";
	cin>>c;
	switch(c)
	{
		case 1:
			d1.getdist();
			d2.getdist();
			d3.add_dist(d1,d2);
			d3.showdist();
			break;
		case 2:
			d1.getdist();
			d2.getdist();
			d3=d1.add_dist(d2);
			d3.showdist();
			break;
		default:
			cout<<"wrong choice"<<endl;
	}	
	return 0;
}
