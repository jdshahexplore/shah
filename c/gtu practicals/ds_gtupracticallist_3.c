#include<stdio.h>
#define size 20
//stack declaration
struct stack
{
	int s[size],top;
}st;
//full condition
int isfull()
{
	if(st.top==size-1)
		return 1;
	else
		return 0;
}
//empty condition
int isempty()
{
	if(st.top==-1)
		return 1;
	else
		return 0;
}
//push function
void push(int n)
{
	st.top++;
	st.s[st.top]=n;
}
//pop function
int pop()
{
	int x;
	x=st.s[st.top];
	st.top--;
	return x;
}
//display function
void display()
{
	int i;
	for(i=st.top;i>=0;i--)
		printf("%d\t",st.s[i]);
}
//peep function
int peep()
{
	return st.s[st.top];
}
//function for changing values
void change(int n,int i)
{
	st.s[st.top-i+1]=n;
}
//main
void main()
{
	int i,c,n;
	st.top=-1;
	printf("--------------------------\nType 1 to push\nType 2 to pop\nType 3 to peep\nType 4 to change\nType 5 to display\nType 0 to exit\n--------------------------\n");
	read:
	printf("\n\nenter choice = ");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			if(isfull())
				printf("stack is full");
			else
			{
				printf("enter number to push = ");
				scanf("%d",&n);
				push(n);
			}
			goto read;
		case 2:
			if(isempty())
				printf("stack is empty");
			else
				printf("popped number = %d",pop());
			goto read;
		case 3:
			if(isempty())
				printf("stack is empty");
			else
				printf("Top of stack = %d",peep());
			goto read;
		case 4:
			if(isempty())
				printf("stack is empty");
			else
			{	
				printf("enter number and position = ");
				scanf("%d%d",&n,&i);
				change(n,i);
			}
			goto read;
		case 5:
			display();
			goto read;
		case 0:
			break;
	}
}
