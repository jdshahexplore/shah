#include<stdio.h>
void merge_sort(int a[],int low,int mid,int high)
{
    int i,l=low,h=high,m=mid+1,c=low;
    int temp[high];
    while((l<=mid) && (m<=high))
    {
        if(a[l]<=a[m])
        {
            temp[c]=a[l];
            l++;
        }
        else
        {
            temp[c]=a[m];
            m++;
        }
        c++;
    }
    if(l>mid)
    {
        for(i=m;i<=high;i++)
        {
            temp[c]=a[i];
            c++;
        }
    }
    else
    {
        for(i=l;i<=mid;i++)
            temp[c++]=a[i];
    }
    for(i=low;i<=high;i++)
        a[i]=temp[i];
}

void partition(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
    	mid=(low+high)/2;
        partition(a,low,mid);
        partition(a,mid+1,high);
        merge_sort(a,low,mid,high);
    }
}

int main()
{
    int i,n;
    printf("enter n = ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
   		scanf("%d",&a[i]);
    partition(a,0,n-1);
    printf("Sorted array\n");
    for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
