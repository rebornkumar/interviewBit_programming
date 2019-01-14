#include<bits/stdc++.h>
using namespace std;
 
 
void DFSUtil(vector<vector<int>>&adj,vector<int>parent,vector<int>&low,vector<int>&dcv,
vector<bool>&vis,vector<bool>&ap,int src,int &t)
{
    vis[src]=true;
    int child=0;
    dcv[src]=t;
    low[src]=t;
    for(int i=0;i<adj[src].size();i++)
    {
        int V=adj[src][i];
        if(vis[V]==false)
        {
            parent[V]=src;
            child++;
            t++;
            DFSUtil(adj,parent,low,dcv,vis,ap,V,t);
 
            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[src]  = min(low[src], low[V]);
            if(parent[src]==-1&&child>1)
            {
                ap[src]=true;
            }
            if(parent[src]!=-1&&low[V]>=dcv[src])
            {
                ap[src]=true;
            }
 
        }
        else if(V!=parent[src])
        {
            low[src]=min(low[src],dcv[V]);
        }
    }
 
}
int main()
{
    //code
    int N,M;
    cin>>N>>M;
    vector<vector<int>>adj(N);
    int X,Y;
    for(int i=0;i<M;i++)
    {
        cin>>X>>Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }
    vector<bool>vis(N,false);
    vector<bool>ap(N,false);
    vector<int>parent(N,-1);
    vector<int>low(N,N);
    vector<int>dcv(N,N);
    int t=0;
    for(int i=0;i<N;i++)
    {
        if(vis[i]==false)
        DFSUtil(adj,parent,low,dcv,vis,ap,i,t);
    }
    for(int i=0;i<N;i++)
    {
        if(ap[i])
        cout<<i<<endl;
    }
    //code
    return 0;
}
