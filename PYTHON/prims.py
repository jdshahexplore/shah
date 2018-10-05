def allvisited():
    for i in visited:
        if i==0:
            return False
    return True

def adjacent():
    min=999
    for i in range(0,n,1):
        if visited[i]==0:
            for j in range(0,n,1):
                if not cost[i][j]==0 and visited[j]==0 and min>cost[i][j]:
                    min=cost[i][j]
                    u=i
                    v=j
    return min,u,v

n=int(input("Enter no. of vertices = "))
m=int(input("Enter no. of edges = "))
cost=[]
visited=[]
#initializing cost matrix
for i in range(0,n,1):
    list=[]
    visited.insert(i,0)
    for j in range(0,n,1):
        list.insert(j,0)
    cost.insert(i,list)
#printing initial stage
for list in cost:
    print(list)

for i in range(0,m,1):
    u,v=int(input("Enter edge(u v) = ")),int(input())
    x=int(input("Enter cost = "))
    cost[u][v]=cost[v][u]=x

for list in cost:
    print(list)

src=next=total=0
i=1
visited[src]=1
print(visited)
while i<n:
    c,src,next=adjacent()
    visited[next]=1
    print(src," -> ",next)
    total+=c
    i+=1
print("Total cost = ",total)
