#include<iostream>
using namespace std;
class Test
{
    int a,b;
    public:
    Test(){a=b=0;}
    void getdata()
    {
        cout<<"\nEnter Two Number : ";
        cin>>a>>b;
    }
    void putdata()
    {
        cout<<"Two Number are : "<<a<<"&"<<b<<endl;
    }
    void setdata(int x,int y)
    {
        a=x;b=y;
    }

};
int main()
{
    Test t1,*t2;
    t2=new Test;
    cout<<"Values by setdata"<<endl;
    t1.setdata(4,5);
    t1.putdata();
    t1.getdata();
    cout<<endl<<"New Values"<<endl;
    t1.putdata();
    cout<<endl<<"Values by setdata"<<endl;
    t2->setdata(9,10);
    t2->putdata();
    t2->getdata();
    cout<<endl<<"New Values"<<endl;
    t2->putdata();

}
