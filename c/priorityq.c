#include<stdio.h>
#define size 5
struct queue
{
	int que[size];
	int f,r;
}pq;
int isfull()
{
	if(pq.r==size-1)
		return 1;
	else
		return 0;
}
int isempty()
{
	if(pq.f>pq.r)
		return 1;
	else
		return 0;
}

int delete()
{
	int x;
	x=pq.que[pq.f];
	pq.f++;
	return x;
}

void insert(int x)
{
	int i;
	i=pq.r;
	while(i>=0 && x<pq.que[i])
	{
		pq.que[i+1]=pq.que[i];
		i--;
	}
	pq.que[i+1]=x;
	pq.r++;
}

void display()
{
	int i;
	for(i=pq.f;i<=pq.r;i++)
		printf("%d\t",pq.que[i]);
}

void main()
{
	int c,x;
	pq.f=0,pq.r=-1;
	printf("----------------\n1 to insert\n2 to delete\n3 to display\n4 to exit\n--------------------\n");
	read:
	printf("enter choice = ");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			if(isfull())
				printf("Queue is full\n\n");
			else
			{
				printf("enter number = ");
				scanf("%d",&x);
				insert(x);
			}
			goto read;
		case 2:
			if(isempty())
				printf("Queue is empty\n\n");
			else
			{
				x=delete();
				printf("number deleted = %d\n\n",x);
			}
			goto read;
		case 3:
			if(isempty())
				printf("Queue is empty\n\n");
			else
			{
				display();
				printf("\n\n");
			}
			goto read;
		case 4:
			break;
		default:
			printf("entered wrong choice\n\n");
			goto read;
	}
}
