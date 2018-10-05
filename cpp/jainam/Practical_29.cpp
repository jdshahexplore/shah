#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
using namespace std;

class Hospital
{
	char name[15],doa[15],disease[15],dod[15];

    public:
    Hospital() {
    	name[0]=doa[0]=disease[0]=dod[0]='\0';
	}
    void getdata();
    void putdata(Hospital);
    void display();
    void show();
    void search(char []);
};

void Hospital::getdata()
{
    cout<<"Enter name = ";
    cin>>name;
    cout<<"Enter admission date = ";
    cin>>doa;
    cout<<"Enter disease = ";
    cin>>disease;
    cout<<"Enter discharge date = ";
    cin>>dod;
}

void Hospital::putdata(Hospital data)
{
	fstream fout;
	fout.open("Hospital",ios::app | ios::out);
	fout.write((char*)&data,sizeof(data));
	fout.close();
}

void Hospital::show()
{
	cout.setf(ios::left, ios::adjustfield);
	cout<<endl<<setw(15)<<"Name :- "<<setw(15)<<name<<endl;
	cout<<setw(15)<<"doa :- "<<setw(15)<<doa<<endl;
	cout<<setw(15)<<"disease :- "<<setw(15)<<disease<<endl;
	cout<<setw(15)<<"dod :- "<<setw(15)<<dod<<endl;
}

void Hospital::display()
{
	Hospital data;
	fstream fin;
	fin.open("Hospital",ios::in);
	if(fin.good())
	{
		cout<<"Details of all patients"<<endl;
		fin.read((char*)&data,sizeof(data));
		while(!fin.eof())
		{
			data.show();
			fin.read((char*)&data,sizeof(data));
		}
	}
	else
		cout<<"There is no patient"<<endl;
	fin.close();
}

void Hospital::search(char pat[])
{
	int j=0;
	Hospital data;
	fstream file;
	file.open("Hospital", ios::in);
	
	file.read((char*)&data,sizeof(data));
	while(!file.eof())
	{
		if(strcmp(pat,data.name)==0)
		{
			data.show();
			j++;
		}
		file.read((char*)&data,sizeof(data));		
	}
	
	if(j==0)
		cout<<"Patient Not Found"<<endl;
	file.close();
}

int main()
{
	Hospital p;
	int c;
	cout<<"----------------------------------------------"<<endl;
	cout<<"1: To enter info. of new patient"<<endl;
	cout<<"2: To display info. of all patients"<<endl;
	cout<<"3: To search for a patient"<<endl;
	cout<<"4: Exit"<<endl;
	cout<<"----------------------------------------------"<<endl;
	read:
	cout<<endl<<"Enter choice = ";
	cin>>c;
	switch(c)
	{
		case 1:
			cout<<"Enter details of patient"<<endl;
			p.getdata();
			p.putdata(p);
			goto read;
		case 2:
			p.display();
			goto read;
		case 3:
			char name[15];
			cout<<"Enter name of patient = ";
			cin>>name;
			p.search(name);
			goto read;
		case 4:
			break;
		default:
			cout<<"Wrong choice"<<endl;
			goto read;
	}
	return 0;
}
