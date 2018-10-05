#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<windows.h>
#include<conio.h>
using namespace std;

COORD coord={0,0};

class Bank
{
    char holdername[50],address[100],mobile[22],branch[30],acctype[8],balance[20];
	char cardno[25],accno[26],cvv[10],pin[10];
	char filename[17];
    public:
    void getdata();
    void putdata();
    void generatenew();
    void storefile();
    void increment(char[],char[],int);
    void display();
};

void gotoxy(int x,int y)
{
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Bank::storefile()
{
	fstream file;
	file.open("Card",ios::app | ios::out);
	if(file.good())
		file<<filename<<endl;
	file.close();
}

void Bank::increment(char x[],char y[],int i)
{
	if(x[i]!='9')
		y[i]=x[i]+1;
	else
	{
		y[i]='0';
		if(x[i-1]!='9')
			y[i-1]=x[i-1]+1;
		else
		{
			y[i-1]='0';
			if(x[i-2]!='9')
				y[i-2]=x[i-2]+1;
			else
			{
				y[i-2]='0';
				if(x[i-3]!='9')
					y[i-3]=x[i-3]+1;
				else
					cout<<"Account limit reached"<<endl;
			}
		}
	}
}

void Bank::generatenew()
{
	char fname[17];
	fstream f1;
	f1.open("Card",ios::in);
	strcpy(accno,"AccountNo :16042010700001");
	accno[25]='\0';
	strcpy(cardno,"CardNo :5412751234120001");
	cardno[24]='\0';
	strcpy(cvv,"CVV :1457");
	cvv[9]='\0';
	strcpy(pin,"PIN :4253");
	pin[9]='\0';
	if(f1.good())			//If card file exists
	{
		while(!f1.eof())
			f1.read((char*)&fname,sizeof(fname));
		fname[16]='\0';
		
		char cno[25],ano[26],p[10],c[10];
		fstream fin;
		fin.open(fname,ios::in);		//last account created
		if(fin.good())
		{
			fin.getline((char*)&cno,sizeof(cno));
			fin.getline((char*)&cno,sizeof(cno));
			fin.getline((char*)&c,sizeof(c));
			fin.getline((char*)&p,sizeof(p));
			fin.getline((char*)&ano,sizeof(ano));
			
			strcpy(filename,fname);
			filename[16]='\0';
			
			increment(ano,accno,24);
			increment(cno,cardno,23);
			increment(c,cvv,8);
			increment(p,pin,8);
			increment(fname,filename,15);
			
			storefile();
		}
		fin.close();
	}
	else							//It will run only for first account
	{					
		strcpy(filename,"5412751234120001");
		filename[16]='\0';
		storefile();
	}
	f1.close();
}


void Bank::getdata()
{
    char str[100];
    int l;
    system("cls");
    gotoxy(30,3);
	//Account holder
	cout<<"Enter Account holder name :- ";
    gotoxy(65,3);
	cin>>str;
    strcpy(holdername,"Name :");
    strcat(holdername,str);
    l=strlen(holdername);
    holdername[l]='\0';
    gotoxy(30,5);
	//Address
    cout<<"Enter Address :- ";
    gotoxy(65,5);
	cin>>str;
    strcpy(address,"Address :");
    strcat(address,str);
    l=strlen(address);
    address[l]='\0';
    gotoxy(30,7);
	//Mobile number
    cout<<"Enter Mobile Number :- ";
    gotoxy(65,7);
	cin>>str;
    strcpy(mobile,"Mobile No :");
    strcat(mobile,str);
    mobile[21]='\0';
	gotoxy(30,9);
	//Branch of bank
    cout<<"Enter Branch Name :- ";
	gotoxy(65,9);
    cin>>str;
    strcpy(branch,"Branch Name :");
    strcat(branch,str);
    l=strlen(branch);
    branch[l]='\0';
	gotoxy(30,11);
	//Type of account
    cout<<"Saving/Current(s/c)? :- ";
    gotoxy(65,11);
	cin>>str;
    strcpy(acctype,"Type :");
    strcat(acctype,str);
    acctype[7]='\0';
	gotoxy(30,13);
	//Balance
    cout<<"Enter Balance(minimum 1000) :- ";
    gotoxy(65,13);
	cin>>str;
    strcpy(balance,"Balance :");
    strcat(balance,str);
    l=strlen(balance);
    balance[l]='\0';
	//Generating accno,cardno,pin,cvv
    generatenew();
    system("cls");
	gotoxy(40,6);
	cout<<accno;
	gotoxy(40,7);
	cout<<cardno;
	gotoxy(40,8);
	cout<<cvv;
	gotoxy(40,9);
	cout<<pin;
	gotoxy(40,12);
	cout<<"Please change your pin regularly";
	gotoxy(50,15);
	cout<<"Press any key";
	getch();
}

void Bank::putdata()
{
    fstream fout;
    fout.open(filename, ios::app | ios::out);
    if(fout.good())
    {
    	fout<<holdername<<endl;
		fout<<cardno<<endl;
		fout<<cvv<<endl;
		fout<<pin<<endl;
		fout<<accno<<endl;
		fout<<mobile<<endl;
		fout<<balance<<endl;
		fout<<branch<<endl;
		fout<<acctype<<endl;
		fout<<address<<endl;
		fout<<0<<endl;
	}
	else
		cout<<"unauthorized user"<<endl;
    fout.close();
}

void Bank::display()
{
	char cno[17];
	int i=1;
	system("cls");
	gotoxy(40,8);
	cout<<"Enter your card no = ";
	cin>>cno;
	system("cls");
	cno[16]='\0';
	fstream file;
	file.open(cno, ios::in);
	if(file.good())
	{
		char data[100];
		file.getline((char*)&data,sizeof(data));
		while(!file.eof() && i!=11)
		{
			gotoxy(40,i+3);
			if(data[0]=='p')
			cout<<data;
			file.getline((char*)&data,sizeof(data));
			i++;
		}
	}
	else
	{
		gotoxy(40,8);
		cout<<"Unauthorized user";
	}
}


int main()
{
	Bank a1;
    int c;
    read:
    system("cls");
    gotoxy(40,10);
    cout<<"1: To open new account";
    gotoxy(40,11);
	cout<<"2: To see specific account detail";
	gotoxy(40,13);
	cout<<"Enter choice = ";
    cin>>c;
    switch(c)
    {
    	case 1:
    		a1.getdata();
    		a1.putdata();
    		goto read;
    	case 2:
    		a1.display();
    		gotoxy(40,20);
    		cout<<"Press any key";
			getch();
    		goto read;
    	case 3:
    		break;
	}
    return 0;
}
