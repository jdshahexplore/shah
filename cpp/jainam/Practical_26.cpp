#include <iostream>
using namespace std;

class father
{
    protected:
         int age;
    public:
         father(int a)
         {
            age=a;
         }
         virtual void display()
         {
            cout<<"\nI am father.My age is:"<<age;
         }
};

class son:public father
{
    private:
         int ages;
    public:
         son(int y,int x):father(x)
         {
            ages=y;
         }
         void display()
         {
            cout<<endl<<"I am son.My age is: "<<ages;
         }
};
class daughter:public father
{
    private:
         int aged;
    public:
         daughter(int c,int l):father(l)
         {
            aged=c;
         }
         void display()
         {
            cout<<endl<<"I am daughter.My age is: "<<aged;
         }
};

int main()
{
    father f(55);
    son s(2,24);
    daughter d(1,25);
    f.display();
    s.display();
    d.display();
    father *p;
    p=&s;
    p->display();
    p=&d;
    p->display();
    return 0;
}
