#include<stdio.h>
int binary_search(int a[],int n,int key)
{
	int l,h,m;
	l=0;h=n-1;
	while(l<=h)
	{
		m=(l+h)/2;
		if(a[m]==key)
			return (m+1);
		else if(a[m]>key)
			h=m-1;
		else
			l=m+1;
	}
	return -1;
}
void main()
{
	int n,i,key;
	printf("enter size of array = ");
	scanf("%d",&n);
	int a[n];
	printf("enter array in ascending manner\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("enter number you want to search = ");
	scanf("%d",&key);
	n=binary_search(a,n,key);
	if(n!=-1)
		printf("searched number is at index = %d",n);
	else
		printf("number not found");
}
