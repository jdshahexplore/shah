#include<iostream>
#define size 7
using namespace std;

int visited[size];
int cost[size][size];

int allvisited(int n)
{
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
            return 0;
    }
    return 1;
}

int adjacent(int n,int &a,int &b)
{
    int min=999;
    for(int i=0;i<n;i++)
    {
        if(visited[i]!=0)
        {
            for(int j=0;j<n;j++)
            {
                if(cost[i][j]!=0 && visited[j]==0 && min>cost[i][j])
                {
                    min=cost[i][j];
                    a=i;
                    b=j;
                }
            }
        }
    }
    return min;
}

int main()
{
    int n,m,u,v;
    cout<<"Enter no. of vertices = ";
    cin>>n;
    if(n>size)
        return 0;
    cout<<"Enter no.of edges = ";
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cout<<"Enter edge(u v) = ";
        cin>>u>>v;
        cout<<"Enter cost = ";
        cin>>cost[u][v];
        cost[v][u]=cost[u][v];
    }
    int src=0,total=0,next=0;
    visited[src]=1;
    while(!allvisited(n))
    {
        int c=adjacent(n,src,next);
        visited[next]=1;
        cout<<src<<"->"<<next<<endl;
        total=total+c;
    }
    cout<<"Cost = "<<total<<endl;
    return 0;
}
