#include<stdio.h>
#include<string.h>
#define size 20
main()
{
	char str[size],temp;
	int n,i,j;
	printf("enter string = ");
	scanf("%s",str);
	n=strlen(str);
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if((int)str[j]>(int)str[j+1])
			{
				temp=str[j];
				str[j]=str[j+1];
				str[j+1]=temp;
			}
		}
	}
	
	printf("\n\noutput string = %s",str);
}
