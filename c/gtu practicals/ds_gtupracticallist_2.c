#include<stdio.h>
#include<stdlib.h>
//main function
int main()
{
	int n,c,*p,sum,i;
	read:
	sum=0;
	printf("enter your choice\nType 1 to use malloc function\nType 2 to use calloc function\nType 3 to exit\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			printf("enter number = ");
			scanf("%d",&n);
			p=(int*)malloc(n*sizeof(int));
			for(i=0;i<n;i++)
			{
				scanf("%d",(p+i));
				sum=sum+*(p+i);
			}			
			printf("\nsum of values = %d\n\n",sum);
			free(p);
			goto read;
		case 2:
			printf("enter number = ");
			scanf("%d",&n);
			p=(int*)calloc(n,sizeof(int));
			for(i=0;i<n;i++)
			{
				scanf("%d",(p+i));
				sum=sum+*(p+i);
			}			
			printf("\nsum of values = %d\n\n",sum);
			free(p);
			goto read;
		case 3:
			break;
		default:
			printf("wrong choice\n\n");
			goto read;
	}
}
