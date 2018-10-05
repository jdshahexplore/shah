#include<stdio.h>
int main()
{
    int n,p;
    //n = no. of inputs
    scanf("%d,%d",&n,&p);
    int i,j,k,c=0;
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d,",&a[i]);
    for(i=0;i<n-2;i++)
        for(j=i+1;j<n-1;j++)
            for(k=j+1;k<n;k++)
                if(((a[i]+a[j]+a[k])%p)==0)
                    c++;
    printf("%d",c);
    return 0;
}
