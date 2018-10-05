#include<iostream>
#include<math.h>
using namespace std;

double power(double m,int n=2)
{
	double p;
	p=pow(m,n);
	return p;
}

int main()
{
	double m;
	int n,c;
	cout<<"1: for finding square of number\n2: for finding nth power"<<endl;
	cout<<"Enter choice = ";
	cin>>c;
	switch(c)
	{
		case 1:
			cout<<"Enter number = ";
			cin>>m;
			cout<<"Square of "<<m<<" = "<<power(m);
			break;
		case 2:
			cout<<"Enter number and power = ";
			cin>>m>>n;
			cout<<m<<"^"<<n<<" = "<<power(m,n);
			break;
		default:
			cout<<"Wrong choice";
	}
	return 0;
}
