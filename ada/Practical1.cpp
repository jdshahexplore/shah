#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	int c=1,i,j;

	/*printf("1. Bubble Sort\n");
	printf("2. Selection Sort\n");
	printf("3. Insertion Sort\n");

	printf("Enter choice = ");
	scanf("%d",&c);*/

	int n=10,temp;
	/*printf("Enter n = ");
	scanf("%d",&n);*/
	int a[n];
	for(i=0;i<n;i++)
		a[i]=rand()%100;

	switch(c)
	{
		case 1:
			for(i=0;i<n;i++)
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
			break;
		case 2:
			for(i=0;i<n;i++)
			{
				int min=i;
			    for(j=i+1;j<n;j++)
			    {
			        if(a[min]>a[j])
			            min=j;
			    }
			    j=a[min];
			    a[min]=a[i];
			    a[i]=j;
			}
			break;
		case 3:
			for(i=1;i<n;i++)
			{
				temp=a[i];
				j=i-1;
				while (j>=0 && a[j]>temp)
				{
					a[j+1]=a[j];
					j--;
				}
				a[j+1]=temp;
			}
            break;
		case 4:
			break;
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<endl;
	return 0;
}


