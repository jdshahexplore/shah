#include<stdio.h>
struct student
{
	int roll_no,m1,m2,m3;
	char name[50];
}s;
void main()
{
	printf("enter name = ");
	scanf("%s",s.name);
	printf("enter roll_no = ");
	scanf("%d",&s.roll_no);
	printf("enter marks of three subjects = ");
	scanf("%d%d%d",&s.m1,&s.m2,&s.m3);
	printf("\nyour details\n");
	printf("name:\t\t%s\n",s.name);
	printf("roll_no:\t%d\n",s.roll_no);
	printf("marks of three subjects\nm1:\t%d\nm2:\t%d\nm3:\t%d",s.m1,s.m2,s.m3);
}
