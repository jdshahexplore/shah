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
		friend int max(ABC &,DEF &);
};

class DEF
{
	int x;
	public:
		void getdata() {
			cout<<"Enter x = ";
			cin>>x;
		}
		friend int max(ABC &,DEF &);
};

int max(ABC & m,DEF & n)
{
	if(m.a>n.x)
		return m.a;
	else
		return n.x;
}

int main()
{
	ABC m;
	DEF n;
	m.getdata();
	n.getdata();
	cout<<"Maximum = "<<max(m,n);
	return 0;
}
