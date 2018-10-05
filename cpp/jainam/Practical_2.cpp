#include<iostream>
using namespace std;

float cal(int ch)
{
	float a,b;
	cout<<"Enter two numbers = ";
	cin>>a>>b;
	switch(ch)
	{
		case 1:
			return a+b;
		case 2:
			return a-b;
		case 3:
			return a*b;
		case 4:
			return a/b;
	}
}

int main()
{
	int ch;
	cout<<"1: ADD\n2: SUBTRACT\n3: MULTIPLY\n4: DIVIDE\n5: EXIT"<<endl;
	read:
	cout<<"Enter Choice = ";
	cin>>ch;
	if(ch>=1 && ch<=4)
	{
		cout<<"Result = "<<cal(ch)<<endl<<endl;
		goto read;
	}
	else if(ch>5)
	{
		cout<<"Wrong Choice"<<endl<<endl;
		goto read;
	}
}
