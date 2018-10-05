#include<stdio.h>
#define size 10
//stack
int stack[size];
int top=-1;
//full
int isfull()
{
	if(top==size-1)
		return 1;
	else
		return 0;
}
//empty
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
//push
void push(int n)
{
	stack[++top]=n;
}
//pop
int pop()
{
	return stack[top--];
}
//peep
int peep()
{
	return stack[top];
}
//display
void display()
{
	int i;
	for(i=top;i!=-1;i--)
		printf("%d\t",stack[i]);
}
//main
void main()
{
	int c,n;
	read:
	printf("\n\nenter choice\n1 to push\n2 to pop\n3 to peep\n4 to display\n5 to exit\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			if(isfull())
				printf("stack is full");
			else
			{
				printf("enter number = ");
				scanf("%d",&n);
				push(n);
			}
			goto read;
		case 2:
			if(isempty())
				printf("stack is empty");
			else
			{
				n=pop();
				printf("popped element = %d",n);
			}
			goto read;
		case 3:
			if(isempty())
				printf("stack is empty");
			else
			{
				n=peep();
				printf("Top of stack = %d",n);
			}
			goto read;
		case 4:
			if(isempty())
				printf("stack is empty");
			else
				display();
			goto read;
		case 5:
			break;
		default:
			printf("entered wrong choice");
			goto read;
	}
}
