#include<stdio.h>
#define size 5
//queue
int queue[size];
int f=-1,r=-1;
//full
int isfull()
{
	if((f==0 && r==size-1) || r==f-1)
		return 1;
	else
		return 0;
}
//empty
int isempty()
{
	if(r==-1)
		return 1;
	else
		return 0;
}
//enque
void enque(int n)
{
	if(f!=0 && r==size-1)
	{
		r=0;
		queue[r]=n;
	}
	else if(r==-1)
	{
		f=r=0;
		queue[r]=n;
	}
	else
		queue[++r]=n;
}
//deque
int deque()
{
	int n;
	if(f==r)
	{
		n=queue[f];
		f=r=-1;
	}
	else
	{
		n=queue[f];
		f=(f+1)%size;
	}
	return n;
}
//display
void display()
{
	int i;
	if(r>=f)
	{
		for(i=f;i<=r;i++)
			printf("%d\t",queue[i]);
	}
	else
	{
		for(i=f;i<size;i++)
			printf("%d\t",queue[i]);
		for(i=0;i<=r;i++)
			printf("%d\t",queue[i]);
	}
}
//main
void main()
{
	int c,n;
	read:
	printf("\n\nenter choice\n1 to enque\n2 to deque\n3 to display\n4 to exit\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			if(isfull())
				printf("Queue is full");
			else
			{
				printf("enter number = ");
				scanf("%d",&n);
				enque(n);
			}
			goto read;
		case 2:
			if(isempty())
				printf("Queue is empty");
			else
			{
				n=deque();
				printf("dequed element = %d",n);
			}
			goto read;
		case 3:
			if(isempty())
				printf("Queue is empty");
			else
				display();
			goto read;
		case 4:
			break;
		default:
			printf("entered wrong choice");
			goto read;
	}
}
