#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int info;
	struct stack *next;
};

struct stack* push(int n,struct stack *r)
{
	struct stack *newnode;
	newnode=(struct stack*)malloc(sizeof(struct stack));
	newnode->info=n;
	newnode->next=r;
	r=newnode;
	return r;
}

struct stack* pop(struct stack *r)
{
	struct stack *p;
	if(r==NULL)
		printf("stack is empty\n");
	else
	{
		p=r;
		r=r->next;
		free(p);
	}
	return r;
}

int peep(struct stack *r)
{
	return (r->info);
}

void display(struct stack *r)
{
	while(r!=NULL)
	{
		printf("%d\t",r->info);
		r=r->next;
	}
	printf("\n");
}

int main()
{
	struct stack *top;
	int c,n;
	top=NULL;
	read:
	printf("enter your choice\nType 1 to push\nType 2 to pop\nType 3 to display top of stack\nType 4 to display stack\nType 5 to exit\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			printf("enter value = ");
			scanf("%d",&n);
			top=push(n,top);
			goto read;
		case 2:
			top=pop(top);
			goto read;
		case 3:
			n=peep(top);
			printf("top of stack = %d\n",n);
			goto read;
		case 4:
			display(top);
			goto read;
		case 5:
			break;
		default:
			printf("entered wrong choice\n");
			goto read;
	}
}
