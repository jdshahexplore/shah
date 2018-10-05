#include<stdio.h>
#define size 5
//declaration
struct queue
{
	int que[size];
	int f,r;
}q;
//full condition
int isfull()
{
	if((q.r==size-1 && q.f==0) || q.r==q.f-1)
		return 1;
	else
		return 0;
}
//empty condition
int isempty()
{
	if(q.f==-1)
		return 1;
	else
		return 0;
}
//insert function
void insert(int n)
{
	if(q.r==-1)
	{
		q.r=q.f=0;
		q.que[q.r]=n;
	}
	else if(q.f!=0 && q.r==size-1)
	{
		q.r=0;
		q.que[q.r]=n;
	}
	else
	{
		q.r++;
		q.que[q.r]=n;
	}
}
//display function
void display()
{
	int i;
	if(q.r>=q.f)
	{
		for(i=q.f;i<=q.r;i++)
			printf("%d\t",q.que[i]);
	}
	else
	{
		for(i=q.f;i<size;i++)
			printf("%d\t",q.que[i]);
		for(i=0;i<=q.r;i++)
			printf("%d\t",q.que[i]);
	}
}
//delete function
void del()
{
	if(q.f==q.r)
		q.f=q.r=-1;
	else
		q.f=(q.f+1)%size;
}
//main function
void main()
{
	int c,n;
	q.f=q.r=-1;
	read:
	printf("\n\n-------enter choice-------\n1 to insert\n2 to delete\n3 to display\n4 to exit\n--------------------------\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			if(isfull())
				printf("Queue is full");
			else
			{
				printf("enter n = ");
				scanf("%d",&n);
				insert(n);
			}
			goto read;
		case 2:
			if(isempty())
				printf("Queue is empty");
			else
				del();
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
			printf("wrong choice");
			goto read;
	}
}
