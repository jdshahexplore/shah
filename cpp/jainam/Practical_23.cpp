#include<iostream>
using namespace std;

class Time24;

class Time12
{
    int hr,min;
    char t;
    public:
    Time12() {
		hr=min=0;
		t='a';
	}
    void getdata()
    {
        cout<<"Enter hour = ";
        cin>>hr;
        cout<<"Enter minutes = ";
        cin>>min;
        cout<<"Enter am or pm as a or p = ";
        cin>>t;
    }
    void putdata()
    {
        cout<<hr<<":"<<min<<" "<<t<<endl;
    }
    int gethr() {return hr;}
    int getmin() {return min;}
    friend void convert(Time12 &,Time24 &);
};

class Time24
{
    int hr,min;
    public:
    Time24() {hr=min=0;}
    Time24(Time12 & t)
    {
    	hr=t.gethr()+12;
    	min=t.getmin();
	}
    void getdata()
    {
        cout<<"Enter hour = ";
        cin>>hr;
        cout<<"Enter minutes = ";
        cin>>min;
    }
    void putdata()
    {
        cout<<hr<<":"<<min<<endl;
    }
    friend void convert(Time12 &,Time24 &);
};

void convert(Time12 & x,Time24 & y)
{
    if(x.t=='a')
    {
        y.hr=x.hr;
        y.min=x.min;
    }
    else
    {
        y.hr=x.hr+12;
        y.min=x.min;
    }
}

int main()
{
    Time12 t12;
    Time24 t24;
    int c;
    cout<<"1: using friend function\n2: using type conversion\nEnter choice = ";
    cin>>c;
    switch(c)
    {
    	case 1:
    	    t12.getdata();
    		convert(t12,t24);
    		t24.putdata();
    		break;
    	case 2:
    		t12.getdata();
    		t24=t12;
    		t24.putdata();
    		break;
	}
    return 0;
}
