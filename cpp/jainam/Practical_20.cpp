#include<iostream>
using namespace std;

class Space
{
	int x,y,z;
	public:
		void getdata()
		{
			cout<<"Enter values of x, y & z = ";
			cin>>x>>y>>z;
		}
		void putdata() {cout<<"\nx = "<<x<<"\ny = "<<y<<"\nz = "<<z<<endl;}
		void operator -();
};

void Space::operator -()
{
	x=-x;
	y=-y;
	z=-z;
}

int main()
{
	Space s1;
	s1.getdata();
	-s1;
	s1.putdata();
	return 0;
}
