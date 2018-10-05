#include<iostream>
using namespace std;
#define size 5

class stack
{

	int s[size];
	int top;

	public:
		stack(void);
		void push(int);
		int pop(void);
		void display(void);
		int isfull(void)
		{
			if(top==size-1)
				return 1;
			else
				return 0;
		}
		int isempty(void)
		{
			if(top==-1)
				return 1;
			else
				return 0;
		}
};

void stack::push(int n)
{
	top++;
	s[top]=n;
}

int stack::pop(void)
{
	int n;
	n=s[top];
	top--;
	return n;
}

void stack::display(void)
{
	for(int i=top;i>=0;i--)
		cout<<s[i];
}

stack::stack(void)
{
	top=-1;
}

int main(void)
{
	int n,c;
	stack st;
	read:
	cout<<"enter your choice = ";
	cin>>c;
	switch(c)
	{
		case 1:
			if(st.isfull())
				cout<<"Stacks is full"<<endl;
			else
			{
				cout<<"enter n = ";
				cin>>n;
				st.push(n);
			}
			goto read;
		case 2:
			if(st.isempty())
				cout<<"Stack is empty"<<endl;
			else
			{
				n=st.pop();
				cout<<"Popped value = "<<n<<endl;
			}
			goto read;
		case 3:
			if(st.isempty())
				cout<<"Stack is empty"<<endl;
			else
				st.display();
			goto read;
		case 4:
			break;
	}
	return 0;
}
