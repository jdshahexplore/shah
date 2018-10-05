#include<stdio.h>
#include<string.h>
main()
{
	char p[60][100];
	int c=0,i,j;
	printf("enter a paragraph\n");
	scanf("%s",p);
	for(i=0;i<60;i++)
	{
		for(j=0;j<100;j++)
		{
			if(p[i][j]==" ")
				c++;
			else if(p[i][j]=='\0')
				goto label;
		}
	}
	label:
		printf("total = %d",c);
}
