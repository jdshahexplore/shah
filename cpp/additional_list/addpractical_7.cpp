#include<iostream>
using namespace std;

struct ITEM
{
    int number;
    float cost;
}i1;

void setdata()
{
    i1.number=1;
    i1.cost=300;
}

void putdata()
{
    cout<<"item_number = "<<i1.number<<"\nitem_cost = "<<i1.cost<<endl;
}

void getdata()
{
    cout<<"enter item number and item cost"<<endl;
    cin>>i1.number>>i1.cost;
}

struct ITEM setdata(struct ITEM i2)
{
    i2.number=1;
    i2.cost=300;
    return i2;
}

void putdata(struct ITEM i2)
{
    cout<<"item_number = "<<i2.number<<"\nitem_cost = "<<i2.cost<<endl;
}

struct ITEM getdata(struct ITEM i2)
{
    cout<<"enter item number and item cost"<<endl;
    cin>>i2.number>>i2.cost;
    return i2;
}

int main()
{
    ITEM i2;
    int c;
    cout<<"1. Global Variable"<<endl;
    cout<<"2. Local Variable"<<endl;
    cout<<"3. Exit";
    read:
    cout<<endl<<"Enter Choice = ";
    cin>>c;
    switch(c)
    {
        case 1:
            setdata();
            cout<<"-----predefined values-----"<<endl;
            putdata();
            getdata();
            cout<<"--------new values-------"<<endl;
            putdata();
            goto read;
        case 2:
            i2=setdata(i2);
            cout<<"-----predefined values-----"<<endl;
            putdata(i2);
            i2=getdata(i2);
            cout<<"--------new values-------"<<endl;
            putdata(i2);
            goto read;
        case 3:
            break;
    }
    return 0;
}
