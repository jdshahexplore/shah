#include<iostream>
using namespace std;

class student
{
    public:
    int en;
    char name[20];
    void getdata(){cout<<"Enter Enrollment No and Name\n";cin>>en>>name;}
           void display(){cout<<"Enrollment No. : "<<en<<endl<<"Name : "<<name<<endl;}
};

class marks
{
    public:
        int m1,m2,m3;
    void getmarks(){cout<<"Enter Mark of 3 Sub.\n";cin>>m1>>m2>>m3;}

};

class details:public student,public marks
{
    int sum;
    public:
    void total()
    {
        getmarks();
        sum=m1+m2+m3;
    }
    void display()
    {
        getdata();
        total();
        cout<<"Enrollment no : "<<en<<endl<<"Name : "<<name<<endl<<"Total : "<<sum<<endl;
    }
};

int main()
{
  details a;
  a.display();
}
