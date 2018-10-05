#include<iostream>
using namespace std;

int decimal(int x[])
{
    return (x[0]*1+x[1]*2+x[2]*4+x[3]*8);
}

//decimal to binary
void binary(int x[],int s)
{
    int i=0;
    while(s>0)
    {
        x[i]=s%2;
        s/=2;
        i++;
    }
}

void add(int a[],int b[],int c)
{
    int s;
    for(int i=0;i<4;i++)
    {
        s=(a[i]+b[i]+c)%2;
        c=(a[i]*b[i]+((a[i]+b[i])%2)*c);
        a[i]=s;
    }
    if(c==1)
    {
        b[0]=c;
        for(int i=1;i<4;i++)
            b[i]=0;
        add(a,b,0);
    }
}

void checksum(int a[],int n)
{
    int sum=0,p[4],q[4];
    for(int i=0;i<=n;i++)
        sum=sum+a[i];

    if(sum>255)
    {
        cout<<"out of range"<<endl;
        return;
    }
    int bin[8];
    //Initializing array
    for(int i=0;i<8;i++)
        bin[i]=0;

    //converting into binary
    binary(bin,sum);

    for(int i=0;i<4;i++)
    {
        p[i]=bin[i];
        q[i]=bin[i+4];
    }

    add(p,q,0);

    a[n]=15-decimal(p);
    cout<<"a[n] = "<<a[n]<<endl;
}

int main()
{
    int n,k;
    
	cout<<"Enter size of data = ";
    cin>>n;
    int a[n+1];
    
    cout<<endl<<"Enter data"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    a[n]=0;

    checksum(a,n);

    cout<<"checksum value at receiver side = "<<a[n]<<endl;

    cout<<"Enter checksum value = ";
    cin>>k;
    a[n]=k;

    checksum(a,n);

    if(a[n]==0)
        cout<<"-------------Data Accepted------------"<<endl;
    else
        cout<<"-------------Data Discarded------------"<<endl;

    return 0;
}
