#include<stdio.h>
main()
{
	int a[100],i,n,max;
	printf("enter number of elements = ");
	scanf("%d",&n);
	printf("enter values = \n");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	max=a[1];
	for(i=1;i<=n;i++)
	{
		if(max<=a[i])
			max=a[i];
	}
	printf("\nmaximum = %d",max);
}
