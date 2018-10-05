#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
	struct node *prev;
};

struct node* create()
{
	struct node *newnode,*save,*root;
	int n;
	root=NULL;
	printf("enter no(-999 to stop) = ");
	scanf("%d",&n);
	while(n!=-999)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->info=n;
		newnode->next=NULL;
		if(root==NULL)
		{
			root=newnode;
			root->prev=NULL;
		}
		else
		{
			save->next=newnode;
			newnode->prev=save;
		}
		save=newnode;
		printf("enter no(-999 to stop) = ");
		scanf("%d",&n);
	}
	return(root);
}

void display1(struct node *r)
{
	while(r!=NULL)
	{
		printf("%d\t",r->info);
		r=r->next;
	}
	printf("\n\n");
}

void display2(struct node *r)
{
	while(r->next!=NULL)
	{
		r=r->next;
	}
	while(r!=NULL)
	{
		printf("%d\t",r->info);
		r=r->prev;
	}
	printf("\n\n");
}

void main()
{
	struct node *start;
	int c;
	start=create();
	read:
	printf("enter choice\n1 to display left to right\n2 to display right to left\n0 to exit\n");
	scanf("%d",&c);
	switch(c)
	{
		case 0:
			break;
		case 1:
			display1(start);
			goto read;
		case 2:
			display2(start);
			goto read;
		default:
			printf("entered wrong choice\n");
			goto read;
	}
}
