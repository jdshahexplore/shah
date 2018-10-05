#include<stdio.h>
main()
{
	int n,i,j,k,c=65,ch;
	printf("enter number of lines = ");
	scanf("%d",&n);
	printf("enter choice \n 1 for 1st pattern \n 2 for 2nd pattern \n 3 to exit");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			for(i=1;i<=n;i++)
			{
				for(k=n-1;k>=i;k--)
					printf(" ");
				
				for(j=1;j<=i;j++)
				{
					if(j==1 || j==i)
						printf("%c ",c);
					else
						printf("  ");
					c++;
				}
				printf("\n");
			}
			c=c-n;
			for(i=n-1;i>=1;i--)
			{
				for(k=n-1;k>=i;k--)
					printf(" ");
				c=c-i;
				for(j=i;j>=1;j--)
				{
					if(j==i || j==1)
						printf("%c ",c);
					else
						printf("  ");
					c++;
				}
				c=c-i;
				printf("\n");
			}
			break;
		case 2:
			c=c+(n*(n+1))/2;
			for(i=n;i>=1;i--)
			{
				for(k=n;k>i;k--)
					printf(" ");
				c=c-i;
				for(j=i;j>=1;j--)
				{
					if(j==i || j==1)
						printf("%c ",c);
					else
						printf("  ");
					c++;
				}
				c=c-i;
				printf("\n");
			}
			
			for(i=2;i<=n;i++)
			{
				for(k=n;k>i;k--)
					printf(" ");
					
				for(j=1;j<=i;j++)
				{
					c++;
					if(j==1 || j==i)
						printf("%c ",c);
					else
						printf("  ");
				}
				printf("\n");
			}
			
			break;
	}
}
