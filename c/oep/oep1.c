#include<stdio.h>
#include<string.h>
#define size 20
int main()
{
	char str1[size],str2[size],str3[2*size];
	int n,i,j,k;

	printf("enter 1st string = ");
	scanf("%s",str1);
	printf("enter 2nd string = ");
	scanf("%s",str2);

	strcpy(str3,str2);
	n=strlen(str3);

	//reversing second string
	for(i=0;str3[i]!='\0';i++)
		str2[n-i-1]=str3[i];

	i=0,j=0,k=0;
	//main logic
	while(str1[i]!='\0' && str2[j]!='\0')
	{
		str3[k++]=str1[i++];
		str3[k++]=str2[j++];
	}
	
	if(str1[i]!='\0')
	{
		while(str1[i]!='\0')
			str3[k++]=str1[i++];
	}
	
	else if(str2[j]!='\0')
	{
		while(str2[j]!='\0')
			str3[k++]=str2[j++];
	}
	
	printf("\n\nOutput string = %s",str3);
	
	return 0;
}
