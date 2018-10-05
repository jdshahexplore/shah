#include<stdio.h>
main()
{
	int a,b;
	printf("enter two values = ");
	scanf("%d%d",&a,&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("after swapping a is %d and b is %d",a,b);
}
