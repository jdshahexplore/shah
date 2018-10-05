#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter n = ";
    cin>>n;
    int a[n+1];
    for(int i=0;i<=n;i++)
        a[i]=i;
    for(int i=2;i*i<=n;i++)
        if(a[i]!=0)
            for(int j=2*i;j<=n;j+i)
                a[i]=0;
    for(int i=0;i<=n;i++)
        if(a[i]!=0)
            cout<<a[i]<<"\t";
    int sum,c=0;
    for(int i=5;i<=n;i+2)
    {
        if(a[i]==0)
            continue;
        sum=0;
        for(int j=2;j<=i;j++)
        {
            if(a[j]!=0)
            {
                sum+=a[j];
                if (sum==a[i])
                {
                    c++;
                    break;
                }
                else if(sum>a[i])
                    break;
            }
         }
    }
    cout<<endl<<"count = "<<c<<endl;
    return 0;
}
