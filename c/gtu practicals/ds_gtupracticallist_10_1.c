#include<stdio.h>
#include<stdlib.h>
//structure declaration
struct node
{
    int info;
    struct node *next;
};
//create function
struct node* create()
{
    struct node *newnode,*prev,*root;
    int n;
    root=NULL;
    printf("enter n(-999 to stop) = ");
    scanf("%d",&n);
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
        printf("enter n(-999 to stop) = ");
        scanf("%d",&n);
    }
    if(root!=NULL)
        prev->next=root;
    return (root);
}
//length of list
int len(struct node *r)
{
    struct node *p;
    int l=0;
    p=r;
    if(r!=NULL)
    {
        do
        {
            l++;
            r=r->next;
        }while(r!=p);
    }
    return l;
}
//display
void display(struct node *r)
{
    struct node *p;
    p=r;
    do
    {
        printf("%d\t",r->info);
        r=r->next;
    }while(r!=p);
    printf("%d\n\n",r->info);
}
//insert end function
struct node* insert(struct node *r,int x)
{
    struct node *newnode,*p;
    p=r;
    if(r!=NULL)
    {
        while(p->next!=r)
            p=p->next;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->info=x;
        newnode->next=r;
        p->next=newnode;
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->info=x;
        newnode->next=newnode;
        r=newnode;
    }
    return r;
}
//insert before specified
struct node* insertb(struct node *r,int x,int p)
{
    struct node *newnode,*root,*last;
    int l,i;
    root=last=r;
    if(r==NULL)
        root=insert(r,x);
    else
    {
        l=len(r);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->info=x;
        newnode->next=NULL;
        if(p==1)
        {
            while(last->next!=r)
                last=last->next;
            last->next=newnode;
            newnode->next=r;
            root=newnode;
        }
        else
        {
            if(p>l || p<=0)
                printf("Invalid Position\n\n");
            else
            {
                i=2;
                while(i<p)
                {
                    last=last->next;
                    p--;
                }
                newnode->next=last->next;
                last->next=newnode;
            }
        }
    }
    return(root);
}
//delete function
struct node* deletef(struct node *r)
{
    struct node *root;
    root=r;
    while(r->next!=root)
        r=r->next;
    r->next=root->next;
    root=root->next;
    return (root);
}
//delete after position
struct node* deletea(struct node *r,int p)
{
    struct node *root,*temp;
    int l,i;
	root=r;
	l=len(r);
	if(p>=l || p<=0)
		printf("Invalid Position\n\n");
	else
	{
		i=1;
		while(i<p)
		{
			r=r->next;
			p--;
		}
		temp=r->next;
		r->next=temp->next;
	}
	return (root);
}
//main function
void main()
{
    struct node *start;
    int c,x,p,l;
    start=create();
    read:
    printf("enter choice\n1 to insert at end\n2 to insert before specified position\n3 to delete first node\n4 to delete after specified position\n5 to display\n6 to find length\n7 to exit\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
            printf("enter value = ");
            scanf("%d",&x);
            start=insert(start,x);
            goto read;
        case 2:
            printf("enter value and position = ");
            scanf("%d%d",&x,&p);
            start=insertb(start,x,p);
            goto read;
        case 3:
            start=deletef(start);
            goto read;
        case 4:
            printf("enter position = ");
            scanf("%d",&p);
            start=deletea(start,p);
            goto read;
        case 5:
            display(start);
            goto read;
        case 6:
            l=len(start);
            printf("length of list = %d\n\n",l);
            goto read;
        case 7:
            break;
        default:
            printf("wrong choice\n\n");
            goto read;
    }
}
