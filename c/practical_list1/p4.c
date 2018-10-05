#include<stdio.h>
int power(int x,int y)
{
	int i,z=1;
	for(i=1;i<=y;i++)
		z=z*x;
	return z;
}
void swap(int x,int y)
{
	x=x+y;
	y=x-y;
	x=x-y;
	printf("after swapping x is %d and y is %d\n\n",x,y);
}
main()
{
	int x,y,c;
	read:
	printf("enter choice = ");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			printf("enter base and power = ");
			scanf("%d%d",&x,&y);
			printf("%d raised to %d is %d\n\n",x,y,power(x,y));
			goto read;
		case 2:
			printf("enter x and y = ");
			scanf("%d%d",&x,&y);
			swap(x,y);
			goto read;
		case 3:
			break;
		default:
			printf("entered wrong choice\n\n");
			goto read;
	}
}
