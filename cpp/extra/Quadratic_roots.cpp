#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b,c,d,e;
	float x1,x2;
	cout<<"enter coefficients of Quadratic Polynomial = "<<endl;
	cin>>a>>b>>c;
	d=(b*b)-(4*a*c);
	if(d<0)
		cout<<"Roots are Complex";
	else
	{
		e=sqrt(d);
		x1=(float)(-b+e)/(2*a);
		x2=(float)(-b-e)/(2*a);
		if(d==0)
		{
			cout<<"Roots are real and equal"<<endl;
			cout<<"x1 = "<<x1<<endl;
			cout<<"x2 = "<<x2<<endl;
		}
		else
		{
			cout<<"Roots are real and distinct"<<endl;
			cout<<"x1 = "<<x1<<endl;
			cout<<"x2 = "<<x2<<endl;
		}
	}
	return 0;
}
