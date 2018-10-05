#include<stdio.h>
#include<stdlib.h>
#define size 10 
//declaration of tree structure
struct node
{
    int info;
    struct node *left,*right;
};
//declaration of stack
struct stack
{
	struct node *s[size];
	int top;
}st;
//empty stack condition
int isempty()
{
	if(st.top==-1)
		return 1;
	else
		return 0;
}
//insert function
struct node* insert(struct node *tree,int n)
{
    if(tree==NULL)
    {
        tree=(struct node*)malloc(sizeof(struct node));
        tree->info=n;
        tree->left=NULL;
        tree->right=NULL;
    }
    else
    {
        if(n<tree->info)
            tree->left=insert(tree->left,n);
        else
            tree->right=insert(tree->right,n);
    }
    return tree;
}
//create function for binary tree
struct node* create()
{
    struct node *root;
    root=NULL;
    int n;
    printf("enter n (n!=-999) = ");
    scanf("%d",&n);
    while(n!=-999)
    {
        root=insert(root,n);
        printf("enter n (n!=-999) = ");
        scanf("%d",&n);
    }
    return root;
}
//recursive preorder
void preorder1(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("%d\t",tree->info);
        preorder1(tree->left);
        preorder1(tree->right);
    }
}
//recursive inorder
void inorder1(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder1(tree->left);
        printf("%d\t",tree->info);
        inorder1(tree->right);
    }
}
//recursive postorder
void postorder1(struct node *tree)
{
    if(tree!=NULL)
    {
        postorder1(tree->left);
        postorder1(tree->right);
        printf("%d\t",tree->info);
    }
}
//push function
void push(struct node *tree)
{
	st.top++;
	st.s[st.top]=tree;
}
//pop function
struct node* pop()
{
	struct node *p;
	p=st.s[st.top];
	st.top--;
	return p;
}
//peep function
struct node* peep()
{
	return st.s[st.top];
}
//iterative preorder
void preorder2(struct node *tree)
{
	struct node *p;
	st.top=-1;
	push(tree);
	while(!isempty())
	{
		p=pop();
		while(p!=NULL)
		{
			printf("%d\t",p->info);
			if(p->right!=NULL)
				push(p->right);
			p=p->left;
		}
	}
}
//iterative inorder
void inorder2(struct node *tree)
{
	int flag=0;
	st.top=-1;
	while(flag==0)
	{
		while(tree!=NULL)
		{
			push(tree);
			tree=tree->left;
		}
		if(!isempty())
		{
			tree=pop();
			printf("%d\t",tree->info);
			tree=tree->right;
		}
		else
			flag=1;
	}
}
//iterative postorder
void postorder2(struct node *tree)
{
	st.top=-1;
	do
	{
		while(tree!=NULL)
		{
			if(tree->right!=NULL)
				push(tree->right);
			push(tree);
			tree=tree->left;
		}
		tree=pop();
		if(tree->right!=NULL && tree->right==peep())
		{
			pop();
			push(tree);
			tree=tree->right;
		}
		else
		{
			printf("%d\t",tree->info);
			tree=NULL;
		}
	}while(!isempty());
}

int count(struct node *tree)
{
	int c=1;
	if(tree==NULL)
		return 0;
	else
	{
		c=c+count(tree->left);
		c=c+count(tree->right);
		return c;
	}
}

void main()
{
    struct node *tree;
    int c,n;
    printf("enter elements of binary tree\n");
    tree=create();
    read:
    printf("\n\nenter choice\n1 for recursive preorder\n2 for recursive inorder\n3 for recursive postorder\n4 for non-recursive preorder\n5 for non-recursive inorder\n6 for non-recursive postorder\n7 for inserting a node\n8 to count nodes\n9 to exit\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        	if(tree!=NULL)
        		preorder1(tree);
            else
            	printf("Tree is empty");
			goto read;
        case 2:
            if(tree!=NULL)
				inorder1(tree);
            else
            	printf("Tree is empty");
			goto read;
        case 3:
        	if(tree!=NULL)
            	postorder1(tree);
            else
            	printf("Tree is empty");
			goto read;
        case 4:
        	if(tree!=NULL)
        		preorder2(tree);
        	else
            	printf("Tree is empty");
			goto read;
        case 5:
        	if(tree!=NULL)
        		inorder2(tree);
        	else
            	printf("Tree is empty");
			goto read;
        case 6:
        	if(tree!=NULL)
				postorder2(tree);
        	else
            	printf("Tree is empty");
			goto read;
        case 7:
        	printf("enter value for new node = ");
        	scanf("%d",&n);
        	tree=insert(tree,n);
        	goto read;
        case 8:
        	n=count(tree);
        	printf("total number of nodes = %d",n);
        	goto read;
        case 9:
        	break;
        default:
        	printf("entered wrong choice");
        	goto read;
    }
}
