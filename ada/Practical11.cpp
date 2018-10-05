#include<iostream>
#define size 7
using namespace std;

int visit[size][size],cost[size][size];

bool loop(int i,int j,int n,int temp1=999)
{
	int c=0;
	for(int k=0;k<n;k++)
	{
		if(visit[i][k]==1 && k!=temp1)
		{
			if(loop(k,j,n,i))
				c=1;
		}
	}
	if(i==j || c!=0)
		return true;
	return false;
}

int main()
{
    int n,m,u,v,c=1,total=0;
    cout<<"Enter no. of vertices = ";
    cin>>n;
    if(n>size)
        return 0;
    cout<<"Enter no.of edges = ";
    cin>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        	cost[i][j]=999;
    }
    for(int i=0;i<m;i++)
    {
        cout<<"Enter edge(u v) = ";
        cin>>u>>v;
        cout<<"Enter cost = ";
        cin>>cost[u][v];
        cost[v][u]=cost[u][v];
    }
    cout<<"---------------------Solution--------------------"<<endl;
    while(c<n)
    {
        int min=999;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(min>cost[i][j])
                {
                    min=cost[i][j];
                    u=i;
                    v=j;
                }
            }
        }
        cost[u][v]=cost[v][u]=999;
        if(!loop(u,v,n))
        {
        	visit[u][v]=visit[v][u]=1;
        	total+=min;
			cout<<"Minimum = "<<min<<"\ti = "<<u<<"\tj = "<<v<<endl<<endl;
        	c++;
        }
        else
		    visit[u][v]=visit[v][u]=-1;
    }
    cout<<endl<<"Total Cost = "<<total<<endl;
    return 0;
}
