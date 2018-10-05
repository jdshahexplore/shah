#include<iostream>
using namespace std;

class cons
{
	int a,b;
	public:
		cons() {a=b=0;}
		cons(int x) {a=b=x;}
		cons(int x,int y)
		{
			a=x;
			b=y;
		}
		cons(cons & i)
		{
			a=i.a;
			b=i.b;
		}
		void putdata() {cout<<"a = "<<a<<"\tb = "<<b<<endl;}
};

int main()
{
	cons c1;
	cout<<"-----using Default Constructor-----"<<endl;
	c1.putdata();
	cons c2(10);
	cout<<"-----using Single Parameterized Constructor-----"<<endl;
	c2.putdata();
	cons c3(10,20);
	cout<<"-----using Multi Parameterized Constructor-----"<<endl;
	c3.putdata();
	cons c4=c3;
	cout<<"-----using Copy Constructor-----"<<endl;
	c4.putdata();
	return 0;
}
