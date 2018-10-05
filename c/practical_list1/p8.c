#include<stdio.h>
void ins(int [],int,int,int);
void del(int [],int,int);
void dis(int [],int);
void srh(int [],int,int);
main()
{
	int a[100],i,n,c,x,p;
	printf("enter number of elements = ");
	scanf("%d",&n);
	printf("enter %d values = ",n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	read:
	printf("Type 1 to insert\nType 2 to delete\nType 3 to display\nType 4 to search\nType 5 to exit");
	printf("\nenter your choice = ");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			printf("enter number and position = ");
			scanf("%d%d",&x,&p);
			ins(a,n,x,p);n++;goto read;
		case 2:
			printf("enter position = ");
			scanf("%d",&p);
			del(a,n,p);n--;goto read;
		case 3:
			dis(a,n);goto read;
		case 4:
			printf("enter number to be searched = ");
			scanf("%d",&x);
			srh(a,n,x);goto read;
		case 5:break;
		default:printf("\nwrong choice\n");goto read;
	}
}
void ins(int a[],int n,int x,int p)
{
	int i;
	for(i=n;i>=p;i--)
		a[i+1]=a[i];
	a[p]=x;
}
void del(int a[],int n,int p)
{
	int i;
	for(i=p;i<n;i++)
		a[i]=a[i+1];
}
void dis(int a[],int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf("%d\t",a[i]);
	printf("\n\n");
}
void srh(int a[],int n,int x)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(a[i]==x)
			printf("%d\t",i);
	}
	printf("\n\n");
}
