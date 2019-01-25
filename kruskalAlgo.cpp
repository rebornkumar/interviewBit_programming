#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
 
int find(vector<int>parent,int X)
{
    if(parent[X]==-1)
    return X;
    return find(parent,parent[X]);
}
void join(vector<int>&parent,int X,int Y)
{
    int t1=find(parent,X);
    int t2=find(parent,Y);
    parent[t1]=t2;
    return;
}
bool isCycle(vector<int>parent,int X,int Y)
{
    int t1=find(parent,X);
    int t2=find(parent,Y);
    if(t1==t2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
ll kruskal(vector<vector<pair<ll,ll>>>graph,int N)
{
    vector<int>parent(N,-1);
    priority_queue<pair<ll,pair<int,int>>>que;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            int v=graph[i][j].f;
            int w=graph[i][j].s;
            que.push({-w,{i,v}});
        }
    }
    int X,Y,W;
    ll minCost=0;
    int cnt=1;
    while(cnt!=N)
    {
        pair<ll,pair<int,int>>myPair=que.top();
        que.pop();
        W=myPair.f;
        X=myPair.s.f;
        Y=myPair.s.s;
        if(isCycle(parent,X,Y)==false)
        {
            join(parent,X,Y);
            minCost+=(abs(W));
            cnt++;
        }
    }
    return minCost;
}
int main()
{
    //code 
    int N,M;
    cin>>N>>M;
    vector<vector<pair<ll,ll>>>adj(N);
    int X,Y,W;
    for(int i=0;i<M;i++)
    {
        cin>>X>>Y>>W;
        //undirected weighted
        adj[X-1].push_back({Y-1,W});
        adj[Y-1].push_back({X-1,W});
    }
    ll rslt=kruskal(adj,N);
    cout<<rslt<<endl;
    //code
    return 0;
}
