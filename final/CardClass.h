#include<iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
#include<cstdlib>
#include<conio.h>
using namespace std;

COORD coord={0,0};

void gotoxy(int x,int y)
{
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Card
{
    public:
    char cardno[16],accholder[100];
    char pin[4],cvv[4];

    int getCardDitails()
    {
    	system("cls");
    	gotoxy(40,10);
        cout<<"Enter Card No : ";
        gotoxy(60,10);
        cin>>cardno;
        //Card Exist Or Not
        if(detectCardNo())
        {
        	gotoxy(40,12);
            cout<<"CVV No : ";
            gotoxy(60,12);
            cin>>cvv;
            //CVV Correct or Not
            if(detectCVVNo())
            {
            	system("cls");
    			gotoxy(40,10);
                cout<<"PIN No : ";
                gotoxy(50,10);
                cin>>pin;
                //Verify Pin Number
                if(verifyPIN())
                {
                	system("cls");
                	gotoxy(50,10);
                    cout<<"Login Successful";
                    return 1;
                }
                else
                {
                	gotoxy(40,12);
                    cout<<"Wrong Pin Number";
                    return 0;
                }
            }
            else
            {
            	gotoxy(40,14);
                cout<<"Wrong CVV No.";
                return 0;
            }
        }
        else
        {
        	gotoxy(45,13);
            cout<<"Unauthorised User\n";
            return 0;
        }
    }

    int detectCardNo()
    {
        ifstream card(cardno);//Open Acccount File Using account Number
        if(card.good())
        {
            card.close();
            return 1;
        }
        else
        {
            card.close();
            return 0;
        }
    }
    
    int detectCVVNo()
    {
        char temp[100];
        char a[100]="CVV :";
        strcat(a,cvv);
        ifstream card(cardno);//Open Acccount File Using account Number
        while(!card.eof())
        {
            card.getline((char *)&temp,sizeof(temp));
            if(strcmp(temp,a)==0)
            {
                return 1;
            }
        }
        return 0;
    }
    
    int verifyPIN()
    {
        char temp[100];
        char a[100]="PIN :";
        strcat(a,pin);
        ifstream card(cardno);//Open Acccount File Using account Number
        while(!card.eof())
        {
            card.getline((char *)&temp,sizeof(temp));
            if(strcmp(temp,a)==0)
            {
                return 1;
            }
        }
        return 0;
    }

    void resetPIN();
};

void Card :: resetPIN()
{
	system("cls");
	gotoxy(40,10);
    cout<<"Old PIN No : ";
    gotoxy(60,10);
    cin>>pin;
    //Verify Pin Number
    if(verifyPIN())
    {
        char npin[4],vnpin[4];
        gotoxy(40,12);
        cout<<"Enter New PIN : ";
        gotoxy(60,12);
		cin>>npin;
        gotoxy(40,14);
        cout<<"Confirm New PIN : ";
        gotoxy(60,14);
        cin>>vnpin;
        if(strcmp(npin,vnpin)==0)
        {
           // cout<<"hi"<<endl;
            char temp[100],temp1[1000];
            char a[10]="PIN :";
            strcat(a,pin);
            fstream card;
            card.open(cardno,ios::in|ios::out|ios::binary);
            //Open Acccount File Using account Number
            while(!card.eof())
            {
                card.getline((char *)&temp,sizeof(temp));
                if(temp[0]=='P')
                {
                    char b[]="PIN :";
                    strcat(b,npin);

                    b[9]='\0';
                    card.seekp(-strlen(temp)-1,ios::cur);
                    card<<b;
                    gotoxy(40,16);
                    cout<<"Successfully PIN Reset";			//Successfully PIN Reset
                    gotoxy(40,18);
				    cout<<"Press any key";
				    getch();
                }
            }
            card.close();
        }
        else
        {
        	gotoxy(40,16);
            cout<<"PIN Doesn't Match!!!!";
            gotoxy(40,18);
		    cout<<"Press any key";
		    getch();
        }
    }
    else
    {
    	gotoxy(40,12);
  	    cout<<"Wrong PIN!!!!";
  	    gotoxy(40,15);
    	cout<<"Press any key";
    	getch();
    }
}
