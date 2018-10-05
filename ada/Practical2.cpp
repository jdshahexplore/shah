#include<stdio.h>
#include<algorithm>
#include<sys/time.h>
#include<iostream>
using namespace std;

int linear(int a[],int k,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if (a[i]==k)
            return i;
    }
    return -1;
}

int binary(int a[],int k,int n)
{
    int l=0,h=n-1;
    int m;
    while(l<=h)
    {
        m=(l+h)/2;
        if(a[m]>k)
            h=m-1;
        else if(a[m]<k)
            l=m+1;
        else
            return m;
    }
    return -1;
}

int main()
{
	int n=10000;
	//printf("Enter n = ");
	//scanf("%d",&n);
	int c=1,i;
	int a[n];
	for(i=0;i<n;i++)
        a[i]=i;
	int key=-1;
	//printf("1. Linear\n2. Binary\n");
	//printf("Enter choice : ");
	//scanf("%d",&c);
	switch(c)
	{
		case 1:
            i=linear(a,key,n);
			break;
		case 2:
            i=binary(a,key,n);
			break;
	}
	if(i==-1)
        printf("Not found");
    else
        printf("Element found at location : %d",i);
    return 0;
}
