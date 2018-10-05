#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 4
using namespace std;

struct row
{
	char A[size],B[size],C[size],D[size],E[size],F[size],G[size],H[size];
	struct row *next;
};

struct row* initialize()
{
	struct row *root,*newnode,*prev;
    for(int i=1;i<=8;i++)
    {
    	newnode=(struct row*)malloc(sizeof(struct row));
		newnode->next=NULL;
		if(i==1)
    	{
    		strcpy(newnode->A,"RB1");
    		strcpy(newnode->B,"NB1");
			strcpy(newnode->C,"BB1");
    		strcpy(newnode->D,"KB1");
    		strcpy(newnode->E,"QB1");
    		strcpy(newnode->F,"BB2");
    		strcpy(newnode->G,"NB2");
    		strcpy(newnode->H,"RB2");
    		root=newnode;
    		prev=root;
		}
		else if(i==8)
		{
			strcpy(newnode->A,"RW1");
    		strcpy(newnode->B,"NW1");
			strcpy(newnode->C,"BW1");
    		strcpy(newnode->D,"KW1");
    		strcpy(newnode->E,"QW1");
    		strcpy(newnode->F,"BW2");
    		strcpy(newnode->G,"NW2");
    		strcpy(newnode->H,"RW2");
    		prev->next=newnode;
    		prev=newnode;
		}
		else if(i==2)
		{
			strcpy(newnode->A,"PB1");
    		strcpy(newnode->B,"PB2");
    		strcpy(newnode->C,"PB3");
    		strcpy(newnode->D,"PB4");
    		strcpy(newnode->E,"PB5");
    		strcpy(newnode->F,"PB6");
    		strcpy(newnode->G,"PB7");
    		strcpy(newnode->H,"PB8");
    		prev->next=newnode;
    		prev=newnode;
		}
		else if(i==7)
		{
			strcpy(newnode->A,"PW1");
    		strcpy(newnode->B,"PW2");
    		strcpy(newnode->C,"PW3");
    		strcpy(newnode->D,"PW4");
    		strcpy(newnode->E,"PW5");
    		strcpy(newnode->F,"PW6");
    		strcpy(newnode->G,"PW7");
    		strcpy(newnode->H,"PW8");
    		prev->next=newnode;
    		prev=newnode;
		}
		else
		{
			strcpy(newnode->A,"\0");
			strcpy(newnode->B,"\0");
    		strcpy(newnode->C,"\0");
    		strcpy(newnode->D,"\0");
    		strcpy(newnode->E,"\0");
    		strcpy(newnode->F,"\0");
    		strcpy(newnode->G,"\0");
    		strcpy(newnode->H,"\0");
			/*strcpy(newnode->A,"XX0");
    		strcpy(newnode->B,"XX0");
    		strcpy(newnode->C,"XX0");
    		strcpy(newnode->D,"XX0");
    		strcpy(newnode->E,"XX0");
    		strcpy(newnode->F,"XX0");
    		strcpy(newnode->G,"XX0");
    		strcpy(newnode->H,"XX0");*/
			prev->next=newnode;
    		prev=newnode;
		}
	}
    return (root);
}

void display(struct row *board)
{
	int i=8;
	while(board!=NULL)
	{
		cout<<i<<"\t"<<board->A<<"\t"<<board->B<<"\t"<<board->C<<"\t"<<board->D<<"\t";
		cout<<board->E<<"\t"<<board->F<<"\t"<<board->G<<"\t"<<board->H<<"\n\n";
		board=board->next;
		i--;
	}
	cout<<"\t A\t B\t C\t D\t E\t F\t G\t H"<<endl;
}

int checkpathempty(struct row *b,char s[],char e[])
{
	int c=(int)s[0]-64;
	int d=(int)e[0]-64;
	
	while()
}

int main()
{
	struct row *start;
	start=initialize();
	display(start);
	char F[2],T[2];
	cout<<"White move\nFrom = ";
	cin>>F;
	cout<<"To = ";
	cin>>T;
	if(!checkpathempty(start,F,T))
	return 0;
}
