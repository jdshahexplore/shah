#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,maxcap;
    cout<<"Enter no. of items = ";
    cin>>n;
    cout<<"Enter max capacity = ";
    cin>>maxcap;
    float p[n],weight[n],r[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter profit & weight = ";
        cin>>p[i]>>weight[i];
        r[i] = p[i]/weight[i];
    }
    float w=0,profit=0;
    int i,k=0;
    float ans[n]={0};
    while(1)
    {
        for(i=0;i<n;i++)
            if(r[k]<r[i])
                k=i;
        if(w+weight[k]<=maxcap)
        {
            ans[k]=1;
            profit=profit+p[k];
            w=w+weight[k];
            r[k]=0;
        }
        else
        {
            ans[k]=(maxcap-w)/weight[k];
            profit=profit+ans[k]*p[k];
            w=maxcap;
            break;
        }
    }
    cout<<"(";
    for(i=0;i<n;i++)
        cout<<ans[i]<<",";
    cout<<"\b)"<<endl;
    cout<<"Profit = "<<profit<<endl;
    return 0;
}
