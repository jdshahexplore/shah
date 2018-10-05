#include<stdio.h>
int main()
{
	int n,i,j,k=1;
	printf("enter number of  lines = ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d",k);
			k++;
		}
		printf("\n");
	}
	return 0;
}

/*
1
23
456
78910
this is for n=4 lines ansd so on*/
