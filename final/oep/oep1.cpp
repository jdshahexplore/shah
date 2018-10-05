#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<stdlib.h>
using namespace std;

class medicine
{
    public:
    char m_name[20],c_name[20],m_id[2];
    float price;
    void getdata()
    {
    	cout<<"\n Enter the medicine code :";
        cin>>m_id;
        cout<<"\n Enter the medicine name :";
        cin>>m_name;
        cout<<"\n Enter the company name :";
        cin>>c_name;
        cout<<"\n Enter price :";
        cin>>price;
    }
    void putdata(medicine m)
    {
    	fstream fout;
    	fout.open("medi",ios::app|ios::out);
    	fout.write((char*)&m,sizeof(m));
   		fout.close();
	}
	void show()
	{
		cout<<m_id<<endl;
		cout<<m_name<<endl;
		cout<<c_name<<endl;
		cout<<price<<endl;
	}
	void display()
	{
		medicine m;
		fstream fin;
		fin.open("medi",ios::in);
		fin.read((char*)&m,sizeof(m));
		while(!fin.eof())
		{
			m.show();
			fin.read((char*)&m,sizeof(m));
		}
		fin.close();
	}
};

class customer:public medicine
{
	float total;
	public:
	customer()
	{
		total=0;
	}
	void addmed()
	{
		up:
		char name[20];
		cout<<"Enter medicine name = ";
		cin>>name;
		medicine m;
		fstream fin;
		fin.open("medi",ios::in);
		fin.read((char*)&m,sizeof(m));
		while(!fin.eof())
		{
			if(strcmp(m.m_name,name)==0)
			{
				cout<<"medicine found"<<endl;
				fstream fout;
				fout.open("bill",ios::app|ios::out);
				fout.write((char*)&m,sizeof(m));
				fout.close();
				total=total+m.price;
			}
			fin.read((char*)&m,sizeof(m));
		}
		fin.close();
		int i;
		cout<<"continue press 0"<<endl;
		cin>>i;
		if(i==0)
			goto up;
	}
	
	void generate()
	{
		medicine m;
		fstream fin;
		fin.open("bill",ios::in);
		if(fin.good())
		{
			fin.read((char*)&m,sizeof(m));
			while(!fin.eof())
			{
				cout<<m.m_id<<"\t"<<m.m_name<<"\t"<<m.c_name<<"\t"<<m.price<<endl;
				fin.read((char*)&m,sizeof(m));
			}
			cout<<endl<<"Total = "<<total<<endl;
			fin.close();
			remove("bill");
		}
		else
			cout<<"No medicine purchased"<<endl;
	}
};

int main()
{
	medicine m;
	customer c;
	int ch,i=0;
    cout<<"\t\t\t.........WELCOME........";
    do
    {
	    cout<<"\n 1).DISPLAY \n 2).ADD NEW \n 3) purchase \n4) generate \n ENTER THE CHOICE";
    	cin>>ch;

	    switch(ch)
	    {
	        case 1:
	            m.display();
	        	break;
	        case 2:
	            m.getdata();
	            m.putdata(m);
	            break;
	        case 3:
	        	c.addmed();
	        	break;
	        case 4:
	        	c.generate();
	        	break;
	        default:
	                cout<<"PLEASE ENTER THE CREATE CHOICE....";
	    }
	    cout<<"\n do you countinue...(0)";
	    cin>>i;
    }while(i==0);
    return 0;
}
