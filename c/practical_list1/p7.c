#include<stdio.h>
int max(int a[],int n)
{
	int i,max=a[1];
	for(i=1;i<=n;i++)
	{
		if(max<=a[i])
			max=a[i];
	}
	return max;
}
main()
{
	int a[100],i,n;
	printf("enter number of elements = ");
	scanf("%d",&n);
	printf("enter values = ");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("maximum = %d",max(a,n));
}
