#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
    char key[10],str[40];
    cout<<"enter plain text:";
    cin>>str;
    cout<<"enter key = ";
    cin>>key;

    int n=strlen(key);
    int m=strlen(str)/n +1;

    char matrix[m][n];
    int k=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(k<strlen(str))
            {
                matrix[i][j]=str[k];
                k++;
            }
            else
                matrix[i][j]=88;
        }
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"--------Output--------"<<endl;

    int curr=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((key[j]-48)==curr)
                k=j;
        }
        for(int j=0;j<m;j++)
        {
            cout<<matrix[j][k];
        }
        curr++;
    }
    cout<<endl<<"---------------------"<<endl;
}
