#include<iostream>
using namespace std;

class MAX
{
	int a,b;
	
	void maximum()
	{
		if(a>b)
			cout<<a<<" is largest"<<endl;
		else
			cout<<b<<" is largest"<<endl;
	}
	
	public:
	void getdata()
	{
		cout<<"Enter two numbers = ";
		cin>>a>>b;
		maximum();
	}
};

int main()
{
	MAX m;
	m.getdata();
	return 0;
}
