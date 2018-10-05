#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int m,n,k,j;
    //size of dataword
    cout<<"what is size of dataword";
    cin>>n;
    cout<<"What is size of divisor = ";
    cin>>m;
    k=m-1;

    int data[n],codeword[n+k],r[n],div[m],d[n];
    //input dataword
    cout<<"Enter dataword = ";
    for(int i=0;i<n;i++)
        cin>>data[i];
    cout<<"Enter divisor = ";
    for(int i=0;i<m;i++)
        cin>>div[i];
    //generating initial codeword
    for(int i=0;i<n+k;i++)
    {
        if(i<n)
            codeword[i]=data[i];
        else
            codeword[i]=0;
    }
    //final crc code
    int l;
    for(int i=0;i<n;i++)
        d[i]=codeword[i];

    for(int i=0;i<n;i++)
    {
        if(d[0]==1)
        {
            l=0;
            for(j=1;j<n;j++)
            {
            	r[l]=0;
                r[l]=(d[j]+div[j])%2;
                d[j-1]=r[l];
                l++;
            }
            d[j-1]=0;
        }
        else
        {
            l=0;
            for(j=1;j<n;j++)
            {
            	r[l]=0;
                r[l]=d[j];
                d[j-1]=r[l];
                l++;
            }
            d[j-1]=0;
        }
    }
    cout<<endl<<endl<<"output"<<endl;

	for(int i=0;i<k;i++)
		cout<<r[i]<<"\t";
	cout<<endl<<endl;

    for(int i=n;i<n+k;i++)
        codeword[i]=r[i-n];

    for(int i=0;i<n+k;i++)
        cout<<codeword[i]<<"\t";

    //receiver side

    cout<<endl<<"Enter received codeword = ";
    for(int i=0;i<n+k;i++)
        cin>>codeword[i];

    for(int i=0;i<n;i++)
        d[i]=codeword[i];
    m=n;
    for(int i=0;i<n;i++)
    {
        if(d[0]==1)
        {
            l=0;
            for(j=1;j<n;j++)
            {
            	r[l]=0;
                r[l]=(d[j]+div[j])%2;
                d[j-1]=r[l];
                l++;
            }
            d[j-1]=codeword[m];
        }
        else
        {
            l=0;
            for(j=1;j<n;j++)
            {
            	r[l]=0;
                r[l]=d[j];
                d[j-1]=r[l];
                l++;
            }
            d[j-1]=codeword[m];
        }
        m++;
    }

	cout<<endl<<endl;
    l=0;
    for(int i=0;i<k;i++)
    {
    	cout<<r[i]<<"\t";
        if(r[i]!=0)
            l++;
    }
    if(l==0)
        cout<<endl<<"---------NO ERROR---------"<<endl<<"Dataword accepted"<<endl;
    else
        cout<<endl<<"--------ERROR--------"<<endl<<"Dataword discarded"<<endl;

    return 0;
}
