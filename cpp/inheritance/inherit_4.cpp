#include<iostream>
#include<string.h>
using namespace std;

class Student
{
    public:
    string name;
    string En_No;
    void getdata()
    {
        cout<<"Enter name of Student = ";
        cin>>name;
        cout<<"Enter Enrollment_No = ";
        cin>>En_No;
    }
    void putdata()
    {
        cout<<"Student Name = "<<name<<endl;
        cout<<"Enrollment_No = "<<En_No<<endl;
    }
};

class Internal:public Student
{
    public:
    float Internal_marks;
    void getdata()
    {
        Student::getdata();
        cout<<"Enter Internal marks = ";
        cin>>Internal_marks;
    }
    void putdata()
    {
        Student::putdata();
        cout<<"Internal_marks = "<<Internal_marks<<endl;
    }
};

class External:public Student
{
    public:
    float External_marks;
    void getdata()
    {
        cout<<"Enter External marks = ";
        cin>>External_marks;
    }
    void putdata()
    {
        cout<<"External marks = "<<External_marks<<endl;
    }
};

class University
{
    public:
    float University_marks;
    void getdata()
    {
        cout<<"Enter University marks = ";
        cin>>University_marks;
    }
    void putdata()
    {
        cout<<"University marks = "<<University_marks<<endl;
    }
};

class Result:public Internal,public External,public University
{
    public:
    void getdata()
    {
        cout<<"----------Enter informtion of Student-------------"<<endl;
        Internal::getdata();
        External::getdata();
        University::getdata();
    }
    void putdata()
    {
        cout<<"---------Student Information---------"<<endl;
        Internal::putdata();
        External::putdata();
        University::putdata();
    }
};

int main()
{
    Result r;
    r.getdata();
    r.putdata();
    return 0;
}
