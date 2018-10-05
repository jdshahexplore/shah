#include<iostream>
#define PI 3.14
using namespace std;

float volume(float l)
{
	return (l*l*l);
}

float volume(float r,float h)
{
	return (PI*r*r*h);
}

float volume(float l,float b,float h)
{
	return (l*b*h);
}

int main()
{
	float l,b,h,r;
	int ch;
	cout<<"Find Volume of:\n1: Cube\n2: Cylinder\n3: Rectangular Box\n4: Exit"<<endl;
	read:
	cout<<"Enter choice = ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Enter length of side = ";
			cin>>l;
			cout<<"Volume of Cube = "<<volume(l)<<endl<<endl;
			goto read;
		case 2:
			cout<<"Enter radius and height = ";
			cin>>r>>h;
			cout<<"Volume of Cylinder = "<<volume(r,h)<<endl<<endl;
			goto read;
		case 3:
			cout<<"Enter length, breadth and height = ";
			cin>>l>>b>>h;
			cout<<"Volume of Rectangular Box = "<<volume(l,b,h)<<endl<<endl;
			goto read;
		case 4:
			break;
		default:
			cout<<"wrong choice"<<endl<<endl;
			goto read;
	}
	return 0;
}
