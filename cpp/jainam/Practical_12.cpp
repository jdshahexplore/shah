#include<iostream>
using namespace std;

class Static_data
{	
	public:
	static void static_fun()
	{
		static int x=0;
		cout<<x<<"\t";
		x++;
	}
};

int main()
{
	for(int i=0;i<5;i++)
		Static_data :: static_fun();
	return 0;
}
