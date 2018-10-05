#include<stdio.h>
#define size 10
//queue declaration
struct queue
{
	int que[size];
	int f,r;
}q;
//full condition
int isfull()
{
	if(q.r==size-1)
		return 1;
	else
		return 0;
}
//empty condition
int isempty()
{
	if(q.f>q.r)
		return 1;
	else
		return 0;
}
//insert function
void enque(int x)
{
	q.r++;
	q.que[q.r]=x;
}
//delete function
int deque()
{
	int x;
	x=q.que[q.f];
	q.f++;
	return x;
}
//display function
void display()
{
	int i=q.f,j=q.r;
	while(i<=j)
	{
		printf("%d\t",q.que[i]);
		i++;
	}
}

void main()
{
	int c,n;
	q.f=0,q.r=-1;
	read:
	printf("\n\nenter choice\nType 1 to insert\nType 2 to delete\nType 3 to display queue\nType 4 to exit\n");
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
				printf("number dequed = %d\n",n);
			}
			goto read;
		case 3:
			if(isempty())
				printf("Queue is empty");
			else
			{
				printf("\nElements of Queue\n");
				display();
			}
			goto read;
		case 4:
			break;
		default:
			printf("entered wrong choice");
			goto read;
	}
}
