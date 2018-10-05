#include<stdio.h>
main()
{
	int a,b,c;
	read:
	printf("\nenter two values = ");
	scanf("%d%d",&a,&b);
	printf("Type 1 to add\nType 2 to subtract\nType 3 to multiply\nType 4 to divide\nType 5 to exit\n");
	printf("enter your choice = ");
	scanf("%d",&c);
	switch(c)
	{
		case 1:printf("addition = %d\n",add(a,b));goto read;
		case 2:printf("subtraction = %d\n",sub(a,b));goto read;
		case 3:printf("multiplication = %d\n",mul(a,b));goto read;
		case 4:printf("division = %d\n",div(a,b));goto read;
		case 5:break;
		default:printf("\nwrongchoice\n");goto read;
	}
}
int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int div(int a,int b)
{
	return a/b;
}
