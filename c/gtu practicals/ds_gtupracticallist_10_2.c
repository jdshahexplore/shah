#include<stdio.h>
#include<stdlib.h>
//declaration of binary tree
struct node
{
    int info;
    struct node *left,*right;
};
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
//create function of binary tree
struct node* create()
{
    struct node *root;
    root=NULL;
    int n;
    printf("enter n (n!=-999) = ");
    scanf("%d",&n);
    while(n!=-999)
    {
        root=insert(root,n);		//calling insert function
        printf("enter n (n!=-999) = ");
        scanf("%d",&n);
    }
    return root;
}
//Searching function
int search(struct node *tree,int key)
{
    int index=0;
    while(tree!=NULL)
    {
        index++;
        if(tree->info==key)
            return index;		//it returns index of element searched
        else if(key<tree->info)
            tree=tree->left;
        else
            tree=tree->right;
    }
    return -1;		//if element not found it returns -1
}
void main()
{
    struct node *tree;
    int n,index;
    tree=create();
    printf("\nenter number to be searched = ");
    scanf("%d",&n);
    index=search(tree,n);
    if(index!=-1)
    	printf("\nsearch number is at index = %d\n",index);
    else
    	printf("\nelement not found\n");
}
