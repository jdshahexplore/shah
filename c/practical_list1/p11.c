#include<stdio.h>
//declaration of structure
struct student
{
	int roll_no,m1,m2,m3;
	char name[50];
}s[50];
//search1 function
void search1(struct student s[],int n,int x)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(s[i].roll_no==x)
		{
			printf("\n%s your result is\n",s[i].name);
			printf("roll no = \t%d\n",s[i].roll_no);
			printf("marks of 3 subjects\nm1 = \t%d\nm2 = \t%d\nm3 = \t%d\n",s[i].m1,s[i].m2,s[i].m3);
		}
	}
}
//search2 function
struct student search2(struct student s[],int n,int x)
{
	struct student temp;
	int i;
	for(i=1;i<=n;i++)
	{
		if(s[i].roll_no==x)
		{
			temp=s[i];
			break;
		}
	}
	return(temp);
}
//search3 function
struct student* search3(struct student s[],int n,int x)
{
	struct student *temp;
	int i;
	for(i=1;i<=n;i++)
	{
		if(s[i].roll_no==x)
		{
			*temp=s[i];
			break;
		}
	}
	return(temp);
}
//sorting function
void sort(struct student s[],int n)
{
	struct student temp;
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(s[i].roll_no>=s[j].roll_no)
			{
				temp=s[j];
				s[j]=s[i];
				s[i]=temp;
			}
		}
	}
}
//display function
void display(struct student s[],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("\n%s your result is\n",s[i].name);
		printf("roll no = \t%d\n",s[i].roll_no);
		printf("marks of 3 subjects\nm1 = \t%d\nm2 = \t%d\nm3 = \t%d\n",s[i].m1,s[i].m2,s[i].m3);
	}
}
//mainfunction
void main()
{
	int i,n,x,c;
	struct student *p,r;
	char a[20];
	start:
	printf("enter number of students = ");
	scanf("%d",&n);
	if(n<=0)
	{
		printf("invalid input\n");
		goto start;
	}
	else if(n>50)
	{
		printf("number of students exceeded\n");
		goto start;
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			printf("enter name = ");
			scanf("%s",s[i].name);
			printf("enter roll_no = ");
			scanf("%d",&s[i].roll_no);
			entry:
			printf("enter marks of three subjects = ");
			scanf("%d%d%d",&s[i].m1,&s[i].m2,&s[i].m3);
			if(s[i].m1>70 || s[i].m2>70 || s[i].m3>70)
			{
				printf("entered marks should be out of 70\n");
				goto entry;
			}
		}
		read:
		printf("\nType 1 to call search1 function\nType 2 to call search2 function\nType 3 to call search3 function\nType 4 to sort entire list of students in ascending order\nType 0 to exit\n");
		printf("enter your choice = ");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
				break;
			case 1:
				printf("enter roll no of student = ");
				scanf("%d",&x);
				search1(s,n,x);
				goto read;
			case 2:
				printf("enter roll no of student = ");
				scanf("%d",&x);
				r=search2(s,n,x);
				printf("\n%s your result is\n",r.name);
				printf("roll no = \t%d\n",r.roll_no);
				printf("marks of 3 subjects\nm1 = \t%d\nm2 = \t%d\nm3 = \t%d\n",r.m1,r.m2,r.m3);
				goto read;
			case 3:
				printf("enter roll no of student = ");
				scanf("%d",&x);
				p=search3(s,n,x);
				printf("\n%s your result is\n",p->name);
				printf("roll no = \t%d\n",p->roll_no);
				printf("marks of 3 subjects\nm1 = \t%d\nm2 = \t%d\nm3 = \t%d\n",p->m1,p->m2,p->m3);
				goto read;
			case 4:
				sort(s,n);
				display(s,n);
				goto read;
			default:
				printf("entered choice is incorrect\n");
				goto read;
		}
	}
}
