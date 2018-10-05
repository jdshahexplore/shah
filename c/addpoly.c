#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//declaration of structure
struct node
{
	int power_x,coeff;
	struct node *next;
};
//create function
struct node* create()
{
	struct node *newnode,*prev,*root;
	root=NULL;
	int x,c;
	printf("enter coeff and power of x(enter coefficient=0 to stop) = ");
	scanf("%d%d",&c,&x);
	while(c!=0)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->power_x=x;
		newnode->coeff=c;
		newnode->next=NULL;
		if(root==NULL)
			root=newnode;
		else
			prev->next=newnode;
		prev=newnode;
		printf("enter coeff and power of x(enter coefficient=0 to stop) = ");
		scanf("%d%d",&c,&x);
	}
	return(root);
}
//polylast function
struct node* polylast(int nx,int nc,struct node *nr)
{
	struct node *newnode,*root,*prev;
	root=nr;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->power_x=nx;
	newnode->coeff=nc;
	newnode->next=NULL;
	if(nr==NULL)
	{
		nr=newnode;
		return(nr);
	}
	else
	{
		while(nr!=NULL)
		{
			prev=nr;
			nr=nr->next;
		}
		prev->next=newnode;
		return(root);
	}
}
//display function
void display(struct node *nr)
{
	while(nr!=NULL)
	{
		printf("%dx^%d",nr->coeff,nr->power_x);
		nr=nr->next;
		if(nr!=NULL)
			printf(" + ");
	}
}
//main function
main()
{
	struct node *p,*q,*r,*psave,*qsave;
	int a1,a2,d1,d2,d;
	r=NULL;
	p=create();
	q=create();
	printf("\n1st polynomial\n");
	display(p);
	printf("\n\n2nd polynomial\n");
	display(q);
	psave=p;
	qsave=q;
	while(p!=NULL && q!=NULL)
	{
		a1=p->power_x;
		a2=q->power_x;
		d1=p->coeff;
		d2=q->coeff;
		if(a1==a2)
		{
			d=d1+d2;
			if(d!=0)
				r=polylast(a1,d,r);
			p=p->next;
			q=q->next;
		}
		else
		{
			if(a1>a2)
			{
				r=polylast(a1,d1,r);
				p=p->next;
			}
			else
			{
				r=polylast(a2,d2,r);
				q=q->next;
			}
		}
	}
	//if remaining elements
	if(p!=NULL && q==NULL)
	{	
		while(p!=NULL)
		{
			a1=p->power_x;
			d1=p->coeff;
			r=polylast(a1,d1,r);
			p=p->next;
		}
	}
	else if(q!=NULL && p==NULL)
	{
		while(q!=NULL)
		{
			a2=q->power_x;
			d2=q->coeff;
			r=polylast(a2,d2,r);
			q=q->next;
		}
	}
	p=psave;
	q=qsave;
	printf("\n\naddition of two polynomial\n");
	display(r);
}
