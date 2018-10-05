#include<stdio.h>

tower_of_hanoi(int disk,int source,int dest,int mid)
{
	if(disk==1)
		printf("\n move disk from %d to %d",source,dest);
	else
	{
		tower_of_hanoi(disk-1,source,mid,dest);
		printf("\n move disk from %d to %d",source,dest);
		tower_of_hanoi(disk-1,mid,dest,source);
	}
}

void main()
{
	int n;
	printf("enter no. of disk = ");
	scanf("%d",&n);
	tower_of_hanoi(n,1,2,3);
}
