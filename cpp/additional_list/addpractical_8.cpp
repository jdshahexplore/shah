#include<iostream>
using namespace std;

class person
{
    int age;
    char name[20];
    public:
    void getdata();
    void putdata();
};

void person::getdata()
{
    cout<<"enter name = ";
    cin>>name;
    cout<<"enter age = ";
    cin>>age;
}

void person::putdata()
{
    cout<<"your name = "<<name<<endl;
    cout<<"your age = "<<age;
}

int main()
{
    person p;
    p.getdata();
    p.putdata();
    return 0;
}
