#include<stdio.h>
void bubble_sort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void main()
{
	int n,i;
	printf("enter number of elements you want to sort = ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	bubble_sort(a,n);
	printf("array in sorted manner\n\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
