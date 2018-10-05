#include<stdio.h>
#include<stdlib.h>
//declaration of structure
struct node
{
    int info;
    struct node *next;
};
//create function
struct node *create()
{
    struct node *root,*newnode,*prev;
    int n;
    read:
    root=NULL;
    printf("enter no(-999 to stop) = ");
    scanf("%d",&n);
    if(n/10!=0 && n!=-999)
    {
    	printf("wrong way of input(enter only single digit)\n");
    	goto read;
	}
	else
	{
		while(n!=-999)
    	{
        	newnode=(struct node*)malloc(sizeof(struct node));
        	newnode->info=n;
        	newnode->next=NULL;
        	if(root==NULL)
            	root=newnode;
        	else
            	prev->next=newnode;
        	prev=newnode;
        	printf("enter no(-999 to stop) = ");
        	scanf("%d",&n);
        	if(n/10!=0 && n!=-999)
        	{
        		printf("wrong way of input(enter only single digit)\n");
        		goto read;
			}
    	}
	}
    return(root);
}
//reverse
struct node* reverse(struct node *s)
{
    struct node *save,*prev;
    prev=NULL;
    while(s!=NULL)
    {
        save=s->next;
        s->next=prev;
        prev=s;
        s=save;
    }
    return(prev);
}
//insert function
struct node* insert(struct node *s,int x)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=x;
	newnode->next=s;
	return(newnode);
}
//addition
struct node* add(struct node *s1,struct node *s2)
{
	int temp=0,rem;
	struct node *root;
	root=NULL;
	s1=reverse(s1);
	s2=reverse(s2);
	while(s1!=NULL && s2!=NULL)
	{
		temp=temp+(s1->info)+(s2->info);
		rem=temp%10;
		root=insert(root,rem);
		temp=temp/10;
		s1=s1->next;
		s2=s2->next;
	}
	if(s1==NULL && s2==NULL && temp==1)
	{
		root=insert(root,temp);
	}
	else if(s1==NULL && s2!=NULL)
	{
		while(s2!=NULL)
		{
			temp=temp+s2->info;
			rem=temp%10;
			root=insert(root,rem);
			temp=temp/10;
			s2=s2->next;
		}
	}
	else if(s2==NULL && s1!=NULL)
	{
		while(s1!=NULL)
		{
			temp=temp+s1->info;
			rem=temp%10;
			root=insert(root,rem);
			temp=temp/10;
			s1=s1->next;
		}
	}
	return (root);
}
//display function
void display(struct node *s)
{
    while(s!=NULL)
    {
        printf("%d",s->info);
        s=s->next;
    }
}
//main function
main()
{
	struct node *l1,*l2,*l3;
	printf("enter your first number(only 1 bit at a time)\n");
	l1=create();
	printf("enter your second number(only 1 bit at a time)\n");
	l2=create();
	l3=add(l1,l2);
	printf("addition = ");
	if(l3!=NULL)
		display(l3);
	else
		printf("0");
}
