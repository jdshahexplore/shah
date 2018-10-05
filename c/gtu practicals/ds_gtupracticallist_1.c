#include<stdio.h>

void value(int p,int q)
{
	p=100;
	q=200;
}

void reference(int *p,int *q)
{
	*p=100;
	*q=200;
}

void main()
{
	int a,b;
	printf("enter two values = ");
	scanf("%d%d",&a,&b);
	//passed by value
	value(a,b);
	printf("value obtained using passed by value\na=%d\tb=%d\n",a,b);
	//passed by reference
	reference(&a,&b);
	printf("value obtained using passed by reference\na=%d\tb=%d\n",a,b);
}
