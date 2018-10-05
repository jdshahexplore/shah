#include<stdio.h>
#define size 5
//queue
int queue[size];
int f=0,r=-1;
//full
int isfull()
{
	if(r==size-1)
		return 1;
	else
		return 0;
}
//empty
int isempty()
{
	if(f>r)
		return 1;
	else
		return 0;
}
//enque
void enque(int n)
{
	queue[++r]=n;
}
//deque
int deque()
{
	return queue[f++];
}
//display
void display()
{
	int i;
	for(i=f;i<=r;i++)
		printf("%d\t",queue[i]);
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
