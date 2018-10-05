/*Here we are going to write a c program to generate a pattern
1
01
101
0101
*/
//this pattern should be printed as per user input

//so now we start our program

#include<stdio.h>
//this is header file for i/o operations
int main()
{
	int n,i,j;
	printf("enter number of lines = ");
	scanf("%d",&n);
	//this is our logic
	for(i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(j=1;j<=i;j++)
				printf("%d",j%2);
		}
		else
		{
			for(j=2;j<=i+1;j++)
				printf("%d",j%2);
		}
		printf("\n");
	}
	return 0;
}

//so now we compile our file
//our program is successfully compiled with 0 errors
//so we run our program
