#include<stdio.h>
//declaration of structure
struct node
{
    int info;
    struct node *next;
};
//create function
struct node *create()
{
    struct node *root,*newnode,*temp,*prev;
    root=NULL;
    int n;
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
    return (root);
}
//display function
void display(struct node *s)
{
    while(s!=NULL)
    {
        printf("%d\t",s->info);
        s=s->next;
    }
    printf("\n");
}
//max function
int max(struct node *s)
{
    int max=0;
    while(s!=NULL)
    {
        if(max<=s->info)
            max=s->info;
        s=s->next;
    }
    return max;
}
//length function
int len(struct node *s)
{
    int l=0;
    while(s!=NULL)
    {
        l++;
        s=s->next;
    }
    return l;
}
//search function
void search(struct node *s,int x)
{
    int c=0,l=0;
    while(s!=NULL)
    {
        c++;
        if(s->info==x)
        {
            l++;
            printf("%d\t",c);
        }
        s=s->next;
    }
    if(l==0)
        printf("-1\n");
    else
        printf("\n");
}
//replace function
void replace(struct node *s,int x,int y)
{
    while(s!=NULL)
    {
        if(s->info==x)
        {
            s->info=y;
        }
        s=s->next;
    }
}
//sorting
void sort(struct node *s)
{
    struct node *r;
    int temp;
    while(s!=NULL)
    {
        r=s;
        while(r!=NULL)
        {
            if(s->info>=r->info)
            {
                temp=r->info;
                r->info=s->info;
                s->info=temp;
            }
            r=r->next;
        }
        s=s->next;
    }
}
//reverse
struct node* reverse(struct node *s)
{
    struct node *save,*prev,*current;
    current=s;
    prev=NULL;
    while(current!=NULL)
    {
        save=current->next;
        current->next=prev;
        prev=current;
        current=save;
    }
    return(prev);
}
//merge two list
struct node* merge(struct node *s1,struct node *s2)
{
	struct node *newnode,*prev,*root;
	root=NULL;
	while(s1!=NULL)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->info=s1->info;
		newnode->next=NULL;
		if(root==NULL)
			root=newnode;
		else
			prev->next=newnode;
		prev=newnode;
		s1=s1->next;
	}
	while(s2!=NULL)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->info=s2->info;
		newnode->next=NULL;
		prev->next=newnode;
		prev=newnode;
		s2=s2->next;
	}
	return(root);
}
//main function
void main()
{
    struct node *start,*s1,*s2,*s3;
    int c,maximum,l,x,y;
    start=create();
    read:
    printf("enter choice \n 1 to display list \n 2 to display max \n 3 to find length of list \n 4 to search a number in list \n 5 to replace number in list \n 6 to sort list \n 7 to reverse list \n 8 to merge two list \n 0 to exit \n");
    scanf("%d",&c);
    switch(c)
    {
        case 0:
            break;
        case 1:
            display(start);goto read;
        case 2:
            maximum=max(start);
            printf("maximum in list = %d\n",maximum);
            goto read;
        case 3:
            l=len(start);
            printf("length of list = %d\n",l);
            goto read;
        case 4:
            printf("enter number to search = ");
            scanf("%d",&x);
            search(start,x);
            goto read;
        case 5:
            printf("enter number to be replaced = ");
            scanf("%d",&x);
            printf("enter new number = ");
            scanf("%d",&y);
            replace(start,x,y);
            goto read;
        case 6:
            sort(start);
            goto read;
        case 7:
            start=reverse(start);
            goto read;
        case 8:
        	s1=create();
        	s2=create();
        	s3=merge(s1,s2);
        	display(s3);
        	goto read;
        default:
            printf("entered choice is wrong\n");
            goto read;
    }
}
