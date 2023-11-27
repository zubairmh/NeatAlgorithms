// Sourced from uncle
#include <bits/stdc++.h>
using namespace std;
int minindex(vector<int>cost,vector<bool>vis,int n)
{
    int min=32767;
    int index;
    for(int i=0;i<n;i++)
    {
        if(!vis[i] && cost[i]<min)
        {
            min=cost[i];
            index=i;
        }
    }
    return index;
}

void dijkstraL(vector<vector<pair<int,int>>>&adjL,int n)
{
    vector<int>cost(n,INT_MAX);
    vector<bool>complete(n,false);
    vector<int> parent(n,-1);
    int mincost=0;
    parent[0]=-1;
    cost[0]=0;
    for(int i=0;i<n-1;i++)
    {
        int index=minindex(cost,complete,n);
        complete[index]=true;
        for(auto it : adjL[index])
        {
            if(!complete[it.first] && cost[index]!=INT_MAX && cost[index]+it.second<cost[it.first])
            {
                cost[it.first]=cost[index]+it.second;
                parent[it.first]=index;
            }  //for matrix, it.first is j and it.second is adjM[index][j]
        }

    }
    for(int i=1;i<n;i++)
    {
        cout<<"Edge "<<parent[i]<<"->"<<i<<" cost: "<<cost[i]<<endl;
        mincost+=cost[i];
    }
    cout<<"Minimum cost: "<<mincost<<endl;
}

void dijkstraM(int **adjM,int n)
{
    vector<int>cost(n,INT_MAX);
    vector<bool>complete(n,false);
    vector<int> parent(n,-1);
    int mincost=0;
    parent[0]=-1;
    cost[0]=0;
    for(int i=0;i<n-1;i++)
    {
        int index=minindex(cost,complete,n);
        complete[index]=true;
        for(int j=0;j<n;j++)
        {
            if(!complete[j] && cost[index]!=INT_MAX && adjM[index][j] && cost[index]+adjM[index][j]<cost[j])
            {
                cost[j]=cost[index]+adjM[index][j];
                parent[j]=index;
            }
        }

    }
    for(int i=1;i<n;i++)
    {
        cout<<"Edge "<<parent[i]<<"->"<<i<<" cost: "<<cost[i]<<endl;
        mincost+=cost[i];
    }
    cout<<"Minimum cost: "<<mincost<<endl;
}

int main()
{
    int n,e;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";    
    cin>>e;
    vector<vector<pair<int,int>>>adjL(n);
    int x,y,w;
    int** adjM = new int*[n];
    for (int i = 0; i < n; ++i) {
        adjM[i] = new int[n];
        // Initialize the matrix with zeros
        for (int j = 0; j < n; ++j) {
            adjM[i][j] = 0;
        }
    }
    cout<<"Enter the edges from one node to another node and weight: "<<endl;
    for(int i=0;i<e;i++)
    {
        cout<<"Edge "<<i+1<<": "<<endl;
        cin>>x>>y>>w;

        adjL[x].push_back({y,w});
        adjL[y].push_back({x,w});

        adjM[x][y]=w;
        adjM[y][x]=w;
    }

    cout<<"Adjacency List: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(auto it:adjL[i])
        {
            cout<<"("<<it.first<<","<<it.second<<")"<<"->";
        }
        cout<<endl;
    }

    cout<<"Adjacency Matrix: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<adjM[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Dijkstra's Algorithm: "<<endl;
    cout<<"Using Adjacency List: "<<endl;
    dijkstraL(adjL,n);
    cout<<"Using Adjacency Matrix: "<<endl;
    dijkstraM(adjM,n);
}