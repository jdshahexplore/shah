#include<stdio.h>
struct student
{
	int roll_no,m1,m2,m3;
	char name[50];
}s[50];
void result(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("Result of student no. %d\n",i);
		if(s[i].m1>=23 && s[i].m2>=23 && s[i].m3>=23)
			printf("pass\n");
		else
			printf("fail\n");
	}
}
void result_rollno(int x,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(s[i].roll_no==x)
		{
			printf("%s your result is\n",s[i].name);
			printf("m1 =\t%d\nm2 =\t%d\nm3 =\t%d\n",s[i].m1,s[i].m2,s[i].m3);
			if(s[i].m1>=23 && s[i].m2>=23 && s[i].m3>=23)
				printf("pass\n");
			else
				printf("fail\n");
		}
	}
}
void result_name(char a[],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(strcmp(s[i].name,a)==0)
		{
			printf("%s your result is\n",s[i].name);
			printf("roll no = %d\n",s[i].roll_no);
			printf("m1 =\t%d\nm2 =\t%d\nm3 =\t%d\n",s[i].m1,s[i].m2,s[i].m3);
			if(s[i].m1>=23 && s[i].m2>=23 && s[i].m3>=23)
				printf("pass\n");
			else
				printf("fail\n");
		}
	}
}
void high_per(int n)
{
	int i,j,p[n],max;
	for(i=1;i<=n;i++)
		p[i]=(s[i].m1+s[i].m2+s[i].m3)*100/70;
	max=p[1];
	for(i=1;i<=n;i++)
	{
		if(p[i]>=max)
		{
			max=p[i];
			j=i;
		}
	}
	printf("\nyour details\n");
	printf("name:\t\t%s\n",s[j].name);
	printf("roll_no:\t%d\n",s[j].roll_no);
	printf("marks of three subjects\nm1:\t%d\nm2:\t%d\nm3:\t%d",s[j].m1,s[j].m2,s[j].m3);
}
void display(int p)
{
	printf("\nyour details\n");
	printf("name:\t\t%s\n",s[p].name);
	printf("roll_no:\t%d\n",s[p].roll_no);
	printf("marks of three subjects\nm1:\t%d\nm2:\t%d\nm3:\t%d",s[p].m1,s[p].m2,s[p].m3);
}
void main()
{
	int i,n,c,x,p;
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
		printf("\nType 1 to display result of each student\nType 2 to display result by roll no\nType 3 to display result by name\nType 4 to display info. of student who has secured high marks\nType 5 to info. of any student\nType 0 to exit\n");
		printf("enter your choice = ");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
				break;
			case 1:
				result(n);
				goto read;
			case 2:
				printf("enter roll no of student = ");
				scanf("%d",&x);
				result_rollno(x,n);
				goto read;
			case 3:
				printf("enter your name = ");
				scanf("%s",a);
				result_name(a,n);
				goto read;
			case 4:
				high_per(n);
				goto read;
			case 5:
				printf("enter index of student = ");
				scanf("%d",&p);
				display(p);
				goto read;
		}
	}
}
