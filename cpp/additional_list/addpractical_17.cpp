#include<iostream>
using namespace std;

class Array
{
    int n[10];
    public:
    void getdata()
    {
    	cout<<"Enter 10 numbers"<<endl;
        for(int i=0;i<10;i++)
			cin>>n[i];
    }
    void putdata()
    {
    	for(int i=0;i<10;i++)
    		cout<<n[i]<<endl;
    }
    void operator *(int);
};

void Array::operator *(int s)
{
	for(int i=0;i<10;i++)
		n[i]=n[i]*s;
}

int main()
{
    Array a;
    int s;
    a.getdata();
    cout<<endl<<"Enter value of s = ";
    cin>>s;
    cout<<"-----Before Multiplying-----"<<endl;
    a.putdata();
    cout<<"-----After Multiplying by s-----"<<endl;
    a*s;
    a.putdata();
    return 0;
}
