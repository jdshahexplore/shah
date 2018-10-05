#include<stdio.h>
#include<stdlib.h>
//declaration of structure
struct node
{
    int info;
    struct node *prev,*next;
};
//create
struct node *create(struct node ** last)
{
    struct node *newnode,*save,*root;
    int n;
    root=save=*last=NULL;
    printf("enter n(-999 to stop) = ");
    scanf("%d",&n);
    while(n!=-999)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->info=n;
        newnode->next=NULL;
        if(root==NULL)
        {
            newnode->prev=NULL;
            root=newnode;
        }
        else
        {
            newnode->prev=save;
            save->next=newnode;
        }
        save=newnode;
        printf("enter n(-999 to stop) = ");
        scanf("%d",&n);
    }
    if(root!=NULL)
        *last=save;
    return(root);
}
//display
void display(struct node *s,struct node *l)
{
    while(s!=NULL)
    {
        printf("%d\t",s->info);
        s=s->next;
    }
    while(l!=NULL)
    {
        printf("%d\t",l->info);
        l=l->prev;
    }
    printf("\n\n");
}
//insert at first
struct node* insertf(struct node *s,int n)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=n;
	newnode->prev=NULL;
	if(s!=NULL)
	{
		newnode->next=s;
	    s->prev=newnode;
	}
	else
		newnode->next=NULL;
    return(newnode);
}
//insert at end
struct node* insertl(struct node *l,int n)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=n;
    newnode->next=NULL;
    newnode->prev=l;
    l->next=newnode;
    return(newnode);
}
//delete last
struct node* del(struct node *l)
{
    l=l->prev;
    if(l!=NULL)
    	l->next=NULL;
    return (l);
}
//delete before position
struct node* delb(struct node *s,int p)
{
    struct node *root,*save;
    int i=3;
	root=s;
	if(p==2)
	{
		root=s->next;
		root->prev=NULL;
	}
	else
	{
		while(i<p)
		{
			s=s->next;
			p--;
		}
		save=s->next;
		s->next=save->next;
		save=save->next;
		save->prev=s;
	}
	return (root);
}
//delete first
struct node* deletef(struct node *s)
{
	struct node *p;
	p=s;
	s=s->next;
	if(s!=NULL)
		s->prev=NULL;
	free(p);
	return s;
}
//length
int length(struct node *s)
{
    int l=0;
    while(s!=NULL)
    {
        l++;
        s=s->next;
    }
    return (l);
}
//main
void main()
{
    struct node *start,*last;
    int c,x,p,l;
    start=create(&last);
    read:
    printf("enter choice\n1 to display list\n2 to insert node at front\n3 to insert node at end\n4 to delete last node\n5 to delete before specified position\n6 to exit\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        	if(start==NULL)
        		printf("list is empty\n\n");
        	else
            	display(start,last);
            goto read;
        case 2:
            printf("enter value = ");
            scanf("%d",&x);
          	start=insertf(start,x);
          	if(start->next==NULL)
          		last=start;
            goto read;
        case 3:
            printf("enter value = ");
            scanf("%d",&x);
            last=insertl(last,x);
            goto read;
        case 4:
        	if(last==NULL)
        		printf("list is empty\n\n");
        	else
            {
            	last=del(last);
            	if(last==NULL)
            		start=NULL;
			}
            goto read;
        case 5:
        	if(start==NULL)
        		printf("list is empty\n");
        	else
	        {
			    printf("enter position = ");
	            scanf("%d",&p);
	            if(start!=NULL)
	            {
	            	l=length(start);
	            	if(p==l+1)
		            {
						last=del(last);
						if(p==2)
							start=NULL;
		            }
					else if(p<=1 || p>l+1)
		            	printf("Invalid Position\n\n");
		            else
		            	start=delb(start,p);
				}
			}
            goto read;
        case 7:
        	start=deletef(start);
        	if(start==NULL)
        		last=NULL;
        	goto read;
        case 6:
            break;
        default:
        	printf("wrong choice\n\n");
        	goto read;
    }
}
