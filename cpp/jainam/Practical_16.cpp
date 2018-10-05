#include<iostream>
using namespace std;

class DEF;
class ABC
{
	int a;
	public:
		void getdata() {
			cout<<"Enter a = ";
			cin>>a;
		}
		void putdata() {cout<<"a = "<<a<<endl;}
		friend void swap(ABC &,DEF &);
};

class DEF
{
	int x;
	public:
		void getdata() {
			cout<<"Enter x = ";
			cin>>x;
		}
		void putdata() {cout<<"x = "<<x<<endl<<endl;}
		friend void swap(ABC &,DEF &);
};

void swap(ABC & m,DEF & n)
{
	int t=m.a;
	m.a=n.x;
	n.x=t;
}

int main()
{
	ABC m;
	DEF n;
	m.getdata();
	n.getdata();
	cout<<"------Before Swapping-------"<<endl;
	m.putdata();
	n.putdata();
	swap(m,n);
	cout<<"-------After Swapping-------"<<endl;
	m.putdata();
	n.putdata();
	return 0;
}
