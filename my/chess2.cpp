#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

char board[8][8][4];

void initialize()
{
	strcpy(board[0][0],"RB1");
	strcpy(board[0][1],"NB1");
	strcpy(board[0][2],"BB1");
	strcpy(board[0][3],"KB1");
	strcpy(board[0][4],"QB1");
	strcpy(board[0][5],"BB2");
	strcpy(board[0][6],"NB2");
	strcpy(board[0][7],"RB2");
	
	strcpy(board[7][0],"RW1");
	strcpy(board[7][1],"NW1");
	strcpy(board[7][2],"BW1");
	strcpy(board[7][3],"KW1");
	strcpy(board[7][4],"QW1");
	strcpy(board[7][5],"BW2");
	strcpy(board[7][6],"NW2");
	strcpy(board[7][7],"RW2");
	
	strcpy(board[1][0],"PB1");
	strcpy(board[1][1],"PB2");
	strcpy(board[1][2],"PB3");
	strcpy(board[1][3],"PB4");
	strcpy(board[1][4],"PB5");
	strcpy(board[1][5],"PB6");
	strcpy(board[1][6],"PB7");
	strcpy(board[1][7],"PB8");

	strcpy(board[6][0],"PW1");
	strcpy(board[6][1],"PW2");
	strcpy(board[6][2],"PW3");
	strcpy(board[6][3],"PW4");
	strcpy(board[6][4],"PW5");
	strcpy(board[6][5],"PW6");
	strcpy(board[6][6],"PW7");
	strcpy(board[6][7],"PW8");
	
	for(int i=2;i<6;i++)
		for(int j=0;j<8;j++)
			strcpy(board[i][j],"\0");
}

void display()
{
	for(int i=0;i<8;i++)
	{
		cout<<(8-i)<<"\t";
		for(int j=0;j<8;j++)
		{
			cout<<board[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"\t A\t B\t C\t D\t E\t F\t G\t H"<<endl;
}

int guesspiece(int c,int a)
{
	switch(board[c][a][0])
	{
		case 'P':
			return 1;
		case 'K':
			return 2;
		case 'Q':
			return 3;
		case 'B':
			return 4;
		case 'N':
			return 5;
		case 'R':
			return 6;
	}
}

//This function is to move pawn
int pawnmove(int a,int b,int c,int d,int choice)
{
	switch(choice)
	{
		case 1:
			if(c>d)
			{
				if(strcmp(board[d][a],"\0")==0 && strcmp(board[d+1][a],"\0")==0)
				{
					strcpy(board[d][b],board[c][a]);
					strcpy(board[c][a],"\0");
					return 1;
				}
			}
			else
			{
				if(strcmp(board[d][a],"\0")==0 && strcmp(board[d-1][a],"\0")==0)
				{
					strcpy(board[d][b],board[c][a]);
					strcpy(board[c][a],"\0");
					return 1;
				}
			}
		case 2:
			if(strcmp(board[d][a],"\0")==0)
			{
				strcpy(board[d][b],board[c][a]);
				strcpy(board[c][a],"\0");
				return 1;
			}
		case 3:
			if(board[d][b][1]!=board[c][a][1] && strcmp(board[d][b],"\0")!=0)
			{
				strcpy(board[d][b],board[c][a]);
				strcpy(board[c][a],"\0");
				return 1;
			}
	}
	return 0;
}

//This function is to move knight
int knightmove(int a,int b,int c,int d)
{
	if(((d-c==2 || c-d==2) && (a-b==1 || b-a==1)) || ((d-c==1 || c-d==1) && (a-b==2 || b-a==2)))
	{
		if(board[d][b][1]!=board[c][a][1])
		{
			strcpy(board[d][b],board[c][a]);
			strcpy(board[c][a],"\0");
			return 1;
		}
	}
	return 0;
}

//This function is to move rook
int rookmove(int a,int b,int c,int d)
{
	int flag=1;
	if(board[d][b][1]!=board[c][a][1])
	{
		if(c-d!=0 && a-b==0)
		{
			if(c<d)
			{
				for(int i=c+1;i<d;i++)
					if(strcmp(board[i][a],"\0")!=0)
						flag=0;
				if(flag==1)
				{
					strcpy(board[d][b],board[c][a]);
					strcpy(board[c][a],"\0");
					return 1;
				}
				else
					return 0;
			}
			else
			{
				for(int i=d+1;i<c;i++)
					if(strcmp(board[i][a],"\0")!=0)
						flag=0;
				if(flag==1)
				{
					strcpy(board[d][b],board[c][a]);
					strcpy(board[c][a],"\0");
					return 1;
				}
				else
					return 0;
			}
		}
		else if(c-d==0 && a-b!=0)
		{
			if(a<b)
			{
				for(int i=a+1;i<b;i++)
					if(strcmp(board[c][i],"\0")!=0)
						flag=0;
				if(flag==1)
				{
					strcpy(board[d][b],board[c][a]);
					strcpy(board[c][a],"\0");
					return 1;
				}
				else
					return 0;
			}
			else
			{
				for(int i=b+1;i<a;i++)
					if(strcmp(board[c][i],"\0")!=0)
						flag=0;
				if(flag==1)
				{
					strcpy(board[d][b],board[c][a]);
					strcpy(board[c][a],"\0");
					return 1;
				}
				else
					return 0;
			}
		}
	}
	return 0;
}

//This function is to move bishop
int bishopmove(int a,int b,int c,int d)
{
	int i,j;
	int flag=1;
	if(c!=d && a!=b && board[c][a][1]!=board[d][a][1])
	{
		if(c<d)
		{
			if(a<b)
			{
				for(i=c+1,j=a+1;i<d,j<b;i++,j++)
					if(strcmp(board[i][j],"\0")!=0)
						flag=0;
				if(flag==1)
				{
					strcpy(board[d][b],board[c][a]);
					strcpy(board[c][a],"\0");
					return 1;
				}
				else
					return 0;
			}
			else
			{
				for(i=c+1,j=b+1;i<d,j<a;i++,j++)
					if(strcmp(board[i][j],"\0")!=0)
						flag=0;
				if(flag==1)
				{
					strcpy(board[d][b],board[c][a]);
					strcpy(board[c][a],"\0");
					return 1;
				}
				else
					return 0;
			}
		}
		else
		{
			if(a<b)
			{
				for(i=d+1,j=a+1;i<c,j<b;i++,j++)
					if(strcmp(board[i][j],"\0")!=0)
						flag=0;
				if(flag==1)
				{
					strcpy(board[d][b],board[c][a]);
					strcpy(board[c][a],"\0");
					return 1;
				}
				else
					return 0;
			}
			else
			{
				for(i=d+1,j=b+1;i<c,j<a;i++,j++)
					if(strcmp(board[i][j],"\0")!=0)
						flag=0;
				if(flag==1)
				{
					strcpy(board[d][b],board[c][a]);
					strcpy(board[c][a],"\0");
					return 1;
				}
				else
					return 0;
			}
		}
	}
	return 0;
}

//function for white
int whitemove()
{
	char f[2],t[2];
	cout<<"---------White's Turn---------"<<endl;
	cout<<"From = ";
	cin>>f;
	cout<<"To = ";
	cin>>t;
	int a=(int)f[0]-65;//a=3
	int b=(int)t[0]-65;//b=3
	int c=7-((int)f[1]-49);//c=6
	int d=7-((int)t[1]-49);//d=4
	int i;	
	if(d!=c || b!=a)
	{
		switch(guesspiece(c,a))
		{
			case 1:
				if(c==6 && c-d==2 && a-b==0)
					i=pawnmove(a,b,c,d,1);
				else if(c-d==1 && a-b==0)
					i=pawnmove(a,b,c,d,2);
				else if(c-d==1 && (a-b==1 || b-a==1))
					i=pawnmove(a,b,c,d,3);
				else
					return 0;
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				i=bishopmove(a,b,c,d);
				if(i==0)
					return 0;
				break;
			case 5:
				i=knightmove(a,b,c,d);
				if(i==0)
					return 0;
				break;
			case 6:
				i=rookmove(a,b,c,d);
				if(i==0)
					return 0;
				break;
		}
		if(i!=0)
			return 1;
	}
	return 0;
}

int blackmove()
{
	char f[2],t[2];
	cout<<"---------Black's Turn---------"<<endl;
	cout<<"From = ";
	cin>>f;
	cout<<"To = ";
	cin>>t;
	int a=(int)f[0]-65;//a=3
	int b=(int)t[0]-65;//b=3
	int c=7-((int)f[1]-49);//c=6
	int d=7-((int)t[1]-49);//d=4
	int i;	
	if(d!=c || b!=a)
	{
		switch(guesspiece(c,a))
		{
			case 1:
				if(c==1 && d-c==2 && a-b==0)
					i=pawnmove(a,b,c,d,1);
				else if(d-c==1 && a-b==0)
					i=pawnmove(a,b,c,d,2);
				else if(d-c==1 && (a-b==1 || b-a==1))
					i=pawnmove(a,b,c,d,3);
				else
					return 0;
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				i=bishopmove(a,b,c,d);
				if(i==0)
					return 0;
				break;
			case 5:
				i=knightmove(a,b,c,d);
				if(i==0)
					return 0;
				break;
			case 6:
				i=rookmove(a,b,c,d);
				if(i==0)
					return 0;
				break;
		}
		if(i!=0)
			return 1;
	}
	return 0;
}

int main()
{
	initialize();
	display();
	char ch;
	int i;
	do
	{
		white:
		i=whitemove();
		if(i==0)
		{
			cout<<"Illegal move"<<endl;
			goto white;
		}
		display();
		black:
		i=blackmove();
		if(i==0)
		{
			cout<<"Illegal move"<<endl;
			goto black;
		}
		display();
		cout<<"want to continue?(y/n) : ";
		cin>>ch;		
	}while(ch=='y' || ch=='Y');
	return 0;
}
