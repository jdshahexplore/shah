#include<iostream>
#include<string.h>
using namespace std;

char p[2][3];

int main()
{
	strcpy(p[0],"R1");
	strcpy(p[1],"B1");
	int i=0;
	read:
	switch(p[i][0])
	{
		case 'R':
			cout<<"case r"<<endl;
			i++;
			goto read;
		case 'B':
			if(p[0][1]!=p[1][0])
				cout<<"case b"<<endl;
			else
				cout<<"not"<<endl;
			i++;
			goto read;
		default:
			cout<<"Wrong syntax"<<endl;
			break;
	}
}
