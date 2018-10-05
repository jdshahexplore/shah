#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//declaration of structure
struct node
{
	int power_x,power_y,power_z,coeff;
	struct node *next;
};
//create function
struct node* create()
{
	struct node *newnode,*prev,*root;
	root=NULL;
	int x,y,z,c;
	printf("enter coefficient and powers of x,y and z(to stop coeff=0) = ");
	scanf("%d%d%d%d",&c,&x,&y,&z);
	while(c!=0)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->power_x=x;
		newnode->power_y=y;
		newnode->power_z=z;
		newnode->coeff=c;
		newnode->next=NULL;
		if(root==NULL)
			root=newnode;
		else
			prev->next=newnode;
		prev=newnode;
		printf("enter coefficient and powers of x,y and z(to stop coeff=0) = ");
		scanf("%d%d%d%d",&c,&x,&y,&z);
	}
	return root;
}
//polylast function
struct node* polylast(int nx,int ny,int nz,int nc,struct node *nr)
{
	struct node *newnode,*root,*prev;
	root=nr;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->power_x=nx;
	newnode->power_y=ny;
	newnode->power_z=nz;
	newnode->coeff=nc;
	newnode->next=NULL;
	if(root==NULL)
		root=newnode;
	else
	{
		while(nr!=NULL)
		{
			prev=nr;
			nr=nr->next;
		}
		prev->next=newnode;
	}
	return root;
}
//display function
void display(struct node *nr)
{
	while(nr!=NULL)
	{
		printf("%dx^%dy^%dz^%d",nr->coeff,nr->power_x,nr->power_y,nr->power_z);
		nr=nr->next;
		if(nr!=NULL)
			printf(" + ");
	}
}
//main function
main()
{
	struct node *p,*q,*r,*psave,*qsave;
	int a1,a2,b1,b2,c1,c2,d1,d2,d;
	r=NULL;
	printf("enter 1st polynomial\n");
	p=create();
	printf("enter 2nd polynomial\n");
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
		b1=p->power_y;
		b2=q->power_y;
		c1=p->power_z;
		c2=q->power_z;
		d1=p->coeff;
		d2=q->coeff;
		if((a1==a2) && (b1==b2) && (c1==c2))
		{
			d=d1+d2;
			if(d!=0)
				r=polylast(a1,b1,c1,d,r);
			p=p->next;
			q=q->next;
		}
		else
		{
			if((a1>a2) || ((a1==a2) && (b1>b2)) || ((a1==a2) && (b1==b2) && (c1>c2)))
			{
				r=polylast(a1,b1,c1,d1,r);
				p=p->next;
			}
			else
			{
				r=polylast(a2,b2,c2,d2,r);
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
			b1=p->power_y;
			c1=p->power_z;
			d1=p->coeff;
			r=polylast(a1,b1,c1,d1,r);
			p=p->next;
		}
	}
	else if(q!=NULL && p==NULL)
	{
		while(q!=NULL)
		{
			a2=q->power_x;
			b2=p->power_y;
			c2=p->power_z;
			d2=q->coeff;
			r=polylast(a2,b2,c2,d2,r);
			q=q->next;
		}
	}
	p=psave;
	q=qsave;
	if(r==NULL)
		printf("\n\naddition of two polynomial = 0");
	else
	{	
		printf("\n\naddition of two polynomial = ");
		display(r);
	}
}
