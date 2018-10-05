#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<ctime>
#include<iomanip>
#include "CardClass.h"
#define Size 100
using namespace std;

char temp[100];
time_t now;
tm *ltm;

//Mini-Statement
class Statement:public Card
{
    char cno[16];
    public:
    Statement(Card c)
    {
        strcpy(cno,c.cardno);
        cno[16]='\0';
    }
    void ministatement();
};

void mini(int l,char a[])
{
    fstream card,card1;
    int i=0,j=0,k=1,n;

    card.open(a,ios::in|ios::out);			//card opened
    card1.open("temp3.txt",ios::out);			//card1 opened
    
	while(1)
    {
        card.getline((char *)&temp,sizeof(temp));
        if(j==10)
        {
            n=atol(temp)+1;
            card.seekg(0,ios::beg);
            while(!card.eof())
            {
                card.getline((char *)&temp,sizeof(temp));
                if(k==11)
                    card1<<n<<endl;
                else
	                card1<<temp<<endl;
                k++;
            }
            break;
        }
        j++;
    }
    
    card.close();
    card1.close();
    remove(a);
    rename("temp3.txt",a);
}

int menu()
{
	system("cls");
    int n;
    
    for(int i=30;i<=85;i++)
    {
    	gotoxy(i,8);
    	cout<<"-";
    	gotoxy(i,14);
    	cout<<"-";
	}
	
	for(int i=9;i<=13;i++)
	{
		gotoxy(30,i);
		cout<<"|";
		gotoxy(57,i);
		cout<<"|";
		gotoxy(85,i);
		cout<<"|";
	}
    
    gotoxy(35,9);
    cout<<"1 : Balance Inquiry";
    gotoxy(60,9);
	cout<<"4 : Withdraw Balance";
	
    gotoxy(35,11);
    cout<<"2 : Reset PIN";
    gotoxy(60,11);
	cout<<"5 : Deposit Balance";
	
    gotoxy(35,13);
    cout<<"3 : Fund Transfer";
    gotoxy(60,13);
	cout<<"6 : Mini Statement";
	
	gotoxy(50,16);
	cout<<"Enter choice = ";
    cin>>n;
    return n;
}

void balanceInquiry(Card c)
{
	system("cls");
    char temp[100];
    int i=0;
    char a[100]="Balance :";
    ifstream card(c.cardno);//Open Acccount File Using account Number
    while(!card.eof())
    {
        card.getline((char *)&temp,sizeof(temp));
        if(i==0)
        {
        	gotoxy(40,8);
        	cout<<"Hello Mr. ";
        	for(int i=6;temp[i]!='\0';i++)
        		cout<<temp[i];
        	gotoxy(40,10);
		}
        if(i==6)
            cout<<"Your Current "<<temp;
        i++;
    }
    gotoxy(50,15);
    cout<<"Press any key";
    getch();
}

void fundTransfer(Card c)
{
	system("cls");
    fstream card1,cardb,card2,card3;
    char temp[100];
    int i=0,j=0,k=1;
    char a[100]="Balance :";
    fstream card;
	card.open(c.cardno, ios::in);		//Open Acccount File Using account Number    //card opened
	gotoxy(20,8);
    while(!card.eof())
    {
        card.getline((char *)&temp,sizeof(temp));
        if(i==6)
            cout<<"Current "<<temp;
        i++;
    }
    card.close();			// card closed
    char benaccno[16];
    gotoxy(20,10);
    cout<<"Enter Beneficiary Account No : ";
    gotoxy(85,10);
	cin>>benaccno;
	gotoxy(20,12);
    cout<<"Confirm Beneficiary Account No: "<<benaccno<<" (Y/N) : ";
    char yn;
    gotoxy(85,12);
	cin>>yn;
    if(yn=='y' || yn=='Y')
    {
        cardb.open(benaccno,ios::in);			//cardb opened
        if(!cardb.good())
        {
        	gotoxy(40,15);
            cout<<"!!!Beneficiary account does not exist!!!";
            cardb.close();				//cardb closed
            return;
        }
        else
        	cardb.close();				//cardb closed
        
		char transferamt[10],l[100];
        int decamt,incamt;
        char deecamt[100];
        system("cls");
        gotoxy(30,12);
        cout<<"Enter amount to be transfered : ";
        gotoxy(70,12);
		cin>>transferamt;
        int i=0;

        card.open(c.cardno,ios::in|ios::out);			//card opened
        card1.open("temp1.txt",ios::out);				//card1 opened
        card2.open("temp2.txt",ios::out);				//card2 opened
        //Open Acccount File Using account Number
        while(1)
        {
            card.getline((char *)&temp,sizeof(temp));
            int le=strlen(temp);
            if(j==6)
            {
                for(i=9;temp[i]!='\0';i++)
                {
                    l[i-9]=temp[i];
                }
                decamt=atoi(l)-atoi(transferamt);
				if(atoi(l)<atoi(transferamt))
                {
                    card.seekg(0,ios::beg);
                    while(!card.eof())
                    {
                        card.getline((char *)&temp,sizeof(temp));
                        card1<<temp<<endl;
                        k++;
                    }
                    gotoxy(20,16);
                    cout<<"!!!! Entered Amount is Greater Than Current Balance !!!!";
                    gotoxy(35,18);
                    cout<<"!!!! Transaction Failed !!!!";
                    card.close();			//card closed
                    card1.close();			//card1 closed
                    card2.close();			//card2 closed
                    return;
                }
                else
                {
	                card.close();			//card closed
    	            mini(1,c.cardno);										//jump to mini
        	        card.open(c.cardno,ios::in|ios::out);	// card opened
	                while(!card.eof())
	                {
	                    card.getline((char *)&temp,sizeof(temp));
	                    if(k==7)
	                    {
	                        card1<<"Balance :"<<decamt<<endl;
	                    }
	                    else
	                    card1<<temp<<endl;
	                    k++;
	                }
	                break;
                }
            }

            j++;
        }
		card.close();			//card closed
        card1.close();			//card1 closed
        
		remove(c.cardno);
        rename("temp1.txt",c.cardno);
    	
		card3.open(c.cardno,ios::app|ios::out);			//card3 opened
   		if(card3.good())
		   card3<<setw(8)<<"Transfer"<<setw(25)<<benaccno<<setw(10)<<"-"<<atoi(transferamt)<<setw(6)<<ltm->tm_mday<<"-"<<setw(1)<<1+ltm->tm_mon<<"-"<<setw(4)<<1900+ltm->tm_year<<setw(6)<< ltm->tm_hour << ":"<<ltm->tm_min << ":"<<ltm->tm_sec;
		card3.close();					//card3 closed
		j=0;
		k=1;
		cardb.open(benaccno,ios::in|ios::out);
        while(1)
        {
            cardb.getline((char *)&temp,sizeof(temp));		//cardb opened
            if(j==6)
            {
                for(i=9;temp[i]!='\0';i++)
                {
                    l[i-9]=temp[i];
                }
                incamt=atoi(l)+atoi(transferamt);
                cardb.close();			//cardb.closed
                mini(1,benaccno);														//jump to mini
                cardb.open(benaccno,ios::in|ios::out);			//cardb opened
                while(!cardb.eof())
                {
                    cardb.getline((char *)&temp,sizeof(temp));
                    if(k==7)
                    {
                        card2<<"Balance :"<<incamt<<endl;
                    }
                    else
	                    card2<<temp<<endl;
                    k++;
                }
                break;
            }
            j++;
        }
        cardb.close();			//cardb closed
        card2.close();			//card2 closed
        remove(benaccno);
        rename("temp2.txt",benaccno);
        cardb.open(benaccno,ios::app|ios::out);			//cardb opened
        if(cardb.good())
			cardb<<setw(8)<<"Transfer"<<setw(25)<<c.cardno<<setw(10)<<"+"<<atoi(transferamt)<<setw(6)<<ltm->tm_mday<<"-"<<setw(1)<<1+ltm->tm_mon<<"-"<<setw(4)<<1900+ltm->tm_year<<setw(6)<< ltm->tm_hour << ":"<<ltm->tm_min << ":"<<ltm->tm_sec;
		cardb.close();
		gotoxy(35,12);
		cout<<"Amount Transfered Successfully";
	    gotoxy(40,15);
	    cout<<"Press any key";
	    getch();
    }
}

void withdraw(Card c)
{
    char temp[100];
    int flag=1;
    int i=0,j=0,k=1;
    char transferamt[10],l[100];
    int decamt;
    char withdrawamt[100];
    system("cls");
    gotoxy(30,10);
    cout<<"Enter amount to be withdraw : ";
    gotoxy(60,10);
	cin>>withdrawamt;
    fstream card,card1;
    card.open(c.cardno,ios::in|ios::out);
    card1.open("11.txt",ios::out);
    //Open Acccount File Using account Number
    while(1)
    {
        card.getline((char *)&temp,sizeof(temp));
        int le=strlen(temp);
        if(j==6)
        {
            for(i=9;temp[i]!='\0';i++)
            {
                l[i-9]=temp[i];
            }
            decamt=atoi(l)-atoi(withdrawamt);
            if(atoi(l)>atoi(withdrawamt))
            {
                card.close();
                mini(2,c.cardno);
                card.open(c.cardno,ios::in|ios::out);
                while(!card.eof())
                {
                    card.getline((char *)&temp,sizeof(temp));
                    if(k==7)
                    {
                        card1<<"Balance :"<<decamt<<endl;
                    }
                    else
                    	card1<<temp<<endl;
                    k++;
                }

                break;
            }
            else
            {
                flag=0;
                card.seekg(0,ios::beg);
                while(!card.eof())
                {
                    card.getline((char *)&temp,sizeof(temp));
                    card1<<temp<<endl;
                    k++;
                }
                gotoxy(30,12);
                cout<<"!!!! Enter Amount is Greater Than Current Balance !!!!";
                gotoxy(35,14);
				cout<<"!!!! Transaction Failed !!!!";
                return;
            }
        }
        j++;
    }
    card.close();
    card1.close();
    remove(c.cardno);
    rename("11.txt",c.cardno);
    if(flag==1)
    {
		card.open(c.cardno,ios::app|ios::out);
    	card<<setw(8)<<"Withdraw"<<setw(25)<<c.cardno<<setw(10)<<atoi(withdrawamt)<<setw(6)<<ltm->tm_mday<<"-"<<setw(1)<<1+ltm->tm_mon<<"-"<<setw(4)<<1900+ltm->tm_year<<setw(6)<< ltm->tm_hour << ":"<<ltm->tm_min << ":"<<ltm->tm_sec;
	}
	gotoxy(35,12);
	cout<<"Amount Withdrawn Successfully";
    gotoxy(40,15);
    cout<<"Press any key";
    getch();
}

void deposit(Card c)
{
    char temp[100];
    int i=0,j=0,k=1;
    char transferamt[10],l[100];
    int incamt;
    char depositamt[100];
    system("cls");
    gotoxy(30,10);
    cout<<"Enter amount to be deposit : ";
    gotoxy(60,10);
	cin>>depositamt;
    fstream card,card1;
    card.open(c.cardno,ios::in|ios::out);
    card1.open("11.txt",ios::out);
    //Open Acccount File Using account Number
    while(1)
    {
        card.getline((char *)&temp,sizeof(temp));
        int le=strlen(temp);
        if(j==6)
        {
            for(i=9;temp[i]!='\0';i++)
            {
                l[i-9]=temp[i];
            }
            incamt=atoi(l)+atoi(depositamt);
            card.close();
            mini(3,c.cardno);
            card.open(c.cardno,ios::in|ios::out);
            while(!card.eof())
            {
                card.getline((char *)&temp,sizeof(temp));
                if(k==7)
                {
                    card1<<"Balance :"<<incamt<<endl;
                }
                else
                card1<<temp<<endl;
                k++;
            }
            break;
        }
        j++;
    }
    card.close();
    card1.close();
    remove(c.cardno);
    rename("11.txt",c.cardno);
    card.open(c.cardno,ios::app|ios::out);
    card.seekp(0,ios::cur);
    card<<setw(8)<<"Deposit"<<setw(25)<<c.cardno<<setw(10)<<atoi(depositamt)<<setw(6)<<ltm->tm_mday<<"-"<<setw(1)<<1+ltm->tm_mon<<"-"<<setw(4)<<1900+ltm->tm_year<<setw(6)<< ltm->tm_hour << ":"<<ltm->tm_min << ":"<<ltm->tm_sec;
    gotoxy(40,13);
    cout<<"Amount Deposited Successfully";
    gotoxy(50,15);
    cout<<"Press any key";
    getch();
}

void Statement::ministatement()
{
    fstream file;
    int i=0;
    char data[100];
    system("cls");
    file.open(cno,ios::in);
    if(file.good())
    {
        while(!file.eof())
        {
            file.getline((char*)&data,sizeof(data));
            i++;
            if(i==10)
                break;
        }
        file.getline((char*)&data,sizeof(data));
        int j=atoi(data);
        file.getline((char*)&data,sizeof(data));
        if(j<10)
        {
            file.getline((char*)&data,sizeof(data));
            while(!file.eof())
            {
                cout<<data<<endl;
                file.getline((char*)&data,sizeof(data));
                i++;
            }
            cout<<data<<endl;
        }
        else
        {
            j=(j-10)*2+13;
            while(j-13!=0)
            {
                file.getline((char*)&data,sizeof(data));
                j--;
            }

            file.getline((char*)&data,sizeof(data));
            while(!file.eof())
            {
           		cout<<data<<endl;
                file.getline((char*)&data,sizeof(data));
                i++;
            }
            cout<<data<<endl;
        }
    }
    gotoxy(50,i+2);
    cout<<"Press any key";
    getch();
}

int main()
{
    now=time(0);
    ltm=localtime(&now);
    Card c;
    char ch;
    read:
    system("cls");
    gotoxy(30,6);
    cout<<"----------------------Welcome to ATM-----------------------";
    gotoxy(10,16);
    cout<<"Developed By:";
    gotoxy(10,17);
    cout<<"Yash Patel           160420107043";
    gotoxy(10,18);
    cout<<"Parth Roy            160420107046";
    gotoxy(10,19);
    cout<<"Saurab Maheshwari    160420107048";
    gotoxy(10,20);
    cout<<"Jainam Shah          160420107051";
    gotoxy(10,21);
    cout<<"Parth Shekhaliya     160420107053";
    gotoxy(80,16);
    cout<<"Faculty:";
    gotoxy(80,17);
    cout<<"Prof. Bhumika Shah";
    gotoxy(80,18);
    cout<<"Prof. Urmi Desai";
    gotoxy(40,10);
    cout<<"Proceed for transaction(Y/N) : ";
	gotoxy(75,10);
    cin>>ch;
    if(ch=='Y' || ch=='y')
    {
    	if(c.getCardDitails())
	    {
	        Statement s(c);
	        switch(menu())
	        {
	            case 1:
		            balanceInquiry(c);
		            goto read;
	            case 2:
		            c.resetPIN();
		            goto read;
		        case 3:
		            fundTransfer(c);
		            goto read;
	            case 4:
		            withdraw(c);
		            goto read;
	            case 5:
		            deposit(c);
		            goto read;
	            case 6:
		            s.ministatement();
		            goto read;
	            default :
	            	gotoxy(50,18);
	            	cout<<"!!!! Transaction Failed !!!!";
	            	goto read;
	        }
	    }
	}
	else
		gotoxy(0,22);
}
