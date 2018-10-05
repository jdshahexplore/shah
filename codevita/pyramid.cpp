#include<iostream>
using namespace std;

int main()
{
    int n,num;
    cin>>n;
    int a=1,b=1;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>i;j--)
            cout<<" ";
        for(int j=0;j<=i;j++)
        {
            num = 2*a*(4*b-1);
            if(num<10)
                cout<<"0000"<<num;
            else if(num<100)
                cout<<"000"<<num;
            else if(num<1000)
                cout<<"00"<<num;
            else if(num<10000)
                cout<<"0"<<num;
            else
                cout<<num;
            a++;
            b++;
            if (j<i)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
