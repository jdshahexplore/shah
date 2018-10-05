#include<iostream>
#include<stack>
#include<queue>
#define size 10
using namespace std;

int visited[size]={0};
int graph[size][size]={0};

int adjacent(int v,int n)
{
    for(int i=0;i<n;i++)
        if(graph[v][i]==1 && visited[i]==0)
            return i;
    return (-1);
}

void DFS(int src,int n,stack <int> s)
{
    s.push(src);
    visited[src]=1;
    cout<<src<<"\t";
    while(!s.empty())
    {
        int vertex=adjacent(s.top(),n);
        if(vertex==-1)
            s.pop();
        else
            DFS(vertex,n,s);
    }
}

void BFS(int src,int n,queue <int> q)
{
    q.push(src);
    visited[src]=-1;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        cout<<v<<"\t";
        visited[v]=1;
        for(int i=0;i<n;i++)
            if(graph[v][i]==1 && visited[i]==0)
            {
                q.push(i);
                visited[i]=-1;
            }
    }
}

int main()
{
    int n;
    cout<<"Enter no. of vertices = ";
    cin>>n;
    //if(n>size)
      //  return 0;
    int i,j;
    char c;
    cout<<"Note: Node index should start from 0"<<endl<<endl;
    do
    {
        cout<<"Enter edge(u v) = ";
        cin>>i>>j;
        graph[i][j]=1;
        cout<<"Do you want to continue(y/n) = ";
        cin>>c;
    }while(c=='y' || c=='Y');
    cout<<"Enter Choice : ";
    cin>>j;
    cout<<"Enter Source Node : ";
    cin>>i;
    stack <int> s;
    queue <int> q;
    switch(j)
    {
        case 1:
            cout<<"\n\nDepth First Search"<<endl;
            DFS(i,n,s);
            break;
        case 2:
            cout<<"\n\nBreadth First Search"<<endl;
            BFS(i,n,q);
            break;
    }
    return 0;
}
