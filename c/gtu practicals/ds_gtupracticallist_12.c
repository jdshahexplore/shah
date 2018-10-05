#include<stdio.h>
void quicksort(int a[],int low,int high)
{
    int i,j,pivot,temp;
    if(low<high)
    {
        pivot=low;
        i=low;
    	j=high;
    	while(i<j)
	    {
        	while(a[i]<=a[pivot] && i<high)
            	i++;
        	while(a[j]>a[pivot])
            	j--;
        	if(i<j)
			{
	            temp=a[i];
	            a[i]=a[j];
	            a[j]=temp;
        	}
        }
	    temp=a[pivot];
	    a[pivot]=a[j];
	    a[j]=temp;
	    quicksort(a,low,j-1);
	    quicksort(a,j+1,high);
    }
}
void main()
{
    int i,n;
    printf("enter size of array = ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements\n",n);
    for(i=0;i<n;i++)
		scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    printf("Sorted elements\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
