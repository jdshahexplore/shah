#include<iostream>
using namespace std;

class Person
{
    int age,weight;
    public:
    Person()
    {
        cout<<"Enter age = ";
        cin>>age;
        cout<<"Enter weight = ";
        cin>>weight;
    }
    Person(Person & I)
    {
        age=I.age;
        weight=I.weight;
    }
    void display()
    {
        cout<<"age = "<<age<<"\nweight = "<<weight<<endl;
    }
};

int main()
{
    Person p1;
    p1.display();
    Person p2=p1;
    cout<<"Values by copy constructor"<<endl;
    p2.display();
    return 0;
}
