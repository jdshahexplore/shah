#include<iostream>
using namespace std;

int minimum(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

void copy(int min[][2],int a[],int k,int n)
{
	int s;
	for(int i=0;i<n;i++)
	{
		if(a[i]==999)
			s=a[i];
		else
			s=a[i]+k;
		if(min[i][1]==0)
			min[i][0]=minimum(min[i][0],s);
	}
}

int findmin(int a[][2],int n)
{
	int j,min=a[0][0];
	for(int i=0;i<n;i++)
	{
		if(a[i][1]==0)
		{
			if(min>a[i][0])
			{
				min=a[i][0];
				j=i;
			}
		}
	}
	return (j+1);
}

int main()
{
    int n;
    //Input vertices
    cout<<"Enter number of vertices = ";
    cin>>n;
    //Input adjacent matrix
    int adj[n][n],s;
    cout<<endl<<"NOTE:- For infinite distance enter 999"<<endl<<endl;
    cout<<"Enter values for adjacent matrix"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
        	if(i==j)
        		adj[i-1][j-1]=999;
        	else if(j>i)
        	{
	            cout<<i<<"->"<<j<<" : ";
    	        cin>>adj[i-1][j-1];
    	        adj[j-1][i-1]=adj[i-1][j-1];
    		}
        }
    }
    //print adjacent matrix
    cout<<endl<<"\n------------------Adjacent Matrix------------------"<<endl;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    		cout<<adj[i][j]<<"\t";
    	cout<<endl;
	}
    //Input source node
    cout<<"Which is Source node?"<<endl;
    cin>>s;
    //Implementing algorithm
    int counter=0,k=0,min[n][2],index=s;
	//Initializing visited matrix to 0
    for(int i=0;i<n;i++)
    {
    	min[i][0]=999;
    	min[i][1]=0;
	}

    while(counter!=n)
    {
    	min[s-1][1]=1;		//marking source node as visited
    	copy(min,adj[s-1],k,n);	
    	s=findmin(min,n);
    	k=min[s-1][0];
    	for(int i=0;i<n;i++)
    		cout<<min[i][0]<<"\t";
    	cout<<endl;
    	counter++;
	}
	cout<<endl<<"-------minimum distances from source node-------"<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<index<<"->"<<i<<" : "<<min[i-1][0]<<endl;
	}
}
