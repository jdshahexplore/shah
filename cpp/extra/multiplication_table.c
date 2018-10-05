//hi i am shah jainam
//here we will learn how to write a cprogram for multiplication table.

#include<stdio.h>   //it is header file
int main()
{
	int n,i;
	printf("enter number = ");   //this statement gives instruction to user
	scanf("%d",&n);		//it will accept input from user
	//now we will use a for loop to generate multiplication table
	for(i=1;i<=10;i++)	//this loop will run 10 times
		printf("%d\t*\t%d\t=\t%d\n",n,i,n*i);
		
	//here as there is single statement in for loop there is no requirement of putting brackets.
	//now we save our file.
	//extension should be .c for c file
	//now to compile press f9
	//it is successfully compiled
	//now press f10 to run program
	//now it will give proper output
	//now you have learn how it can be generated.
	
	//thank you for watching this video.
	return 0;
}
