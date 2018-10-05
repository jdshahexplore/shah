#include<iostream>
using namespace std;
int main()
{
	char ch;
	cout<<"enter a character = ";
	cin>>ch;
	if(!isalpha(ch))
		cout<<"Invalid input";
	else if(isupper(ch))
	{
		if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
			cout<<"entered charcter "<<ch<<" is Vowel";
		else
			cout<<"entered charcter "<<ch<<" is Consonant";
	}
	else
	{
		if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
			cout<<"entered charcter "<<ch<<" is Vowel";
		else
			cout<<"entered charcter "<<ch<<" is Consonant";
	}
	return 0;
}
