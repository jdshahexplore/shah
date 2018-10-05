#include<stdio.h>
#include<stdlib.h>
//declaration
struct node
{
    int info;
    struct node *next;
}st;
//create
struct node *create()
{
    struct node *newnode,*prev,*root;
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
            root=newnode;
        else
            prev->next=newnode;
        prev=newnode;
        printf("enter no(-999 to stop) = ");
        scanf("%d",&n);
    }
    return(root);
}
//length
int len(struct node *r)
{
    int l=0;
    while(r!=NULL)
    {
        l++;
        r=r->next;
    }
    return l;
}
//display
void display(struct node *r)
{
    while(r!=NULL)
    {
        printf("%d\t",r->info);
        r=r->next;
    }
    printf("\n");
}
//insert first
struct node* insertf(struct node *r,int x)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=x;
    newnode->next=r;
    r=newnode;
    return(r);
}
//insert end
struct node* inserte(struct node *r,int x)
{
    struct node *newnode,*end,*root;
    root=r;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=x;
    newnode->next=NULL;
    while(r!=NULL)
    {
        end=r;
        r=r->next;
    }
    end->next=newnode;
    return(root);
}
//delete first
struct node *del(struct node *r)
{
    r=r->next;
    return(r);
}
//delete before specified
struct node* deleteb(struct node *r,int pos)
{
    struct node *root,*prev;
    int l,i;
    root=r;
    l=len(r);
    if(pos==1 || pos>(l+1))
        printf("invalid position\n");
    else
    {
        if(pos==2)
        {
            root=r->next;
        }
        else
        {
            i=0;
            while(i!=pos-2)
            {
                prev=r;
                r=r->next;
                i++;
            }
            prev->next=r->next;
        }
    }
    return(root);
}
//delete after position
struct node* deletea(struct node *r,int pos)
{
    struct node *root,*prev;
    int l,i;
    root=r;
    l=len(r);
    if(pos==0)
        root=r->next;
    else if(pos>=l)
        printf("invalid position\n");
    else
    {
        i=0;
        while(i!=pos)
        {
            prev=r;
            r=r->next;
            i++;
        }
        prev->next=r->next;
    }
    return(root);
}
//insertion sort
struct node* insort(struct node *l,int x)
{
    struct node *newnode,*prev,*root,*save;
    int c=0;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=x;
    newnode->next=NULL;
    if(l==NULL)
    {
        l=newnode;
        return l;
    }
    else
    {
        save=l;
        while(l!=NULL)
        {
            if((l->info)>=(newnode->info))
            {
                c++;
                newnode->next=l;
                prev->next=newnode;
                break;
            }
            prev=l;
            l=l->next;
        }
        if(c==0)
        {
            prev->next=newnode;
        }
        return(save);
    }
}
//main
main()
{
    struct node *start,*list;
    int c,x,p;
    start=create();
    list=NULL;
    read:
    printf("enter choice\n 1 to insert node at front of list\n 2 to insert node at end of list\n 3 to insert node such that list is in ascending order\n 4 to delete first node of list\n 5 to delete node before specified position\n 6 to delete a node after specified position\n 7 to display list\n 8 to display insertion sorted list\n 0 to exit\n");
    scanf("%d",&c);
    switch(c)
    {
        case 0:
            break;
        case 1:
            printf("enter value for newnode = ");
            scanf("%d",&x);
            start=insertf(start,x);
            goto read;
        case 2:
            printf("enter value for newnode = ");
            scanf("%d",&x);
            start=inserte(start,x);
            goto read;
        case 3:
            printf("enter number = ");
            scanf("%d",&x);
            list=insort(list,x);
            goto read;
        case 4:
            start=del(start);
            goto read;
        case 5:
            printf("enter position = ");
            scanf("%d",&p);
            start=deleteb(start,p);
            goto read;
        case 6:
            printf("enter position = ");
            scanf("%d",&p);
            start=deletea(start,p);
            goto read;
        case 7:
            display(start);
            goto read;
        case 8:
            display(list);
            goto read;
        default:
            printf("entered choice is incorrect\n");
            goto read;
    }
}
