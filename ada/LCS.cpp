#include<iostream>
#define size 15
using namespace std;

int c[size][size],d[size][size];

void LCS(char s1[],char s2[],int l1,int l2)
{
	for(int i=0;i<=l1;i++)
		c[i][0]=d[i][0]=0;
	for(int i=0;i<=l2;i++)
		c[0][i]=d[0][i]=0;
	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				c[i][j]=1+c[i-1][j-1];
				d[i][j]=0;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				d[i][j]=1;
			}
			else
			{
				c[i][j]=c[i][j-1];
				d[i][j]=-1;
			}
		}
	}
	cout<<"-------------------C[][]---------------------"<<endl;
	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
			cout<<c[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"---------------------------------------------"<<endl<<endl;
	cout<<"-------------------D[][]---------------------"<<endl;
	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
			cout<<d[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"---------------------------------------------"<<endl;
}
char lcstr[size];
int k=0;
void display(char s1[],char s2[],int i,int j)
{
	if(i==0 || j==0)
		return;
	else if(d[i][j]==1)
	{
		display(s1,s2,i-1,j);
	}
	else if(d[i][j]==-1)
	{
		display(s1,s2,i,j-1);
	}
	else if(d[i][j]==0)
	{
		lcstr[k]=s1[i-1];
		k++;
		display(s1,s2,i-1,j-1);
	}
}

int main()
{
	int l1,l2;
	cout<<"Enter length of s1 & s2 = ";
	cin>>l1>>l2;
	if(l1>=size && l2>=size)
		return 0;
	char s1[l1],s2[l2];
	cout<<"Enter 1st string = ";
	cin>>s1;
	cout<<"Enter 2nd string = ";
	cin>>s2;
	LCS(s1,s2,l1,l2);
	display(s1,s2,l1,l2);
	cout<<"Length of LCS = "<<k<<endl;
	cout<<"LCS = ";
	for(int i=k-1;i>=0;i--)
		cout<<lcstr[i];
	cout<<endl;
	return 0;
}
