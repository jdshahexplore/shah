#include<stdio.h>
main()
{
	int x,y,i,z=1;
	printf("enter two values = ");
	scanf("%d%d",&x,&y);
	for(i=1;i<=y;i++)
		z=z*x;
	printf("%d raised to %d is %d",x,y,z);
}
