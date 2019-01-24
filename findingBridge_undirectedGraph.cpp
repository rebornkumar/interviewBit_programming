#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
 
void DFSUtil(vector<vector<int>>&adj,vector<pair<int,int>>&bridge,vector<int>&parent,
vector<int>&low,vector<int>&dcv,vector<bool>&vis,int src,int &t)
{
    vis[src]=true;
    dcv[src]=t;
    low[src]=t;
 
    for(int i=0;i<adj[src].size();i++)
    {
        int V=adj[src][i];
        if(vis[V]==false)
        {
            t++;
            parent[V]=src;
            DFSUtil(adj,bridge,parent,low,dcv,vis,V,t);
 
 
            low[src]=min(low[src],low[V]);
 
            if(low[V]>dcv[src])
            {
                bridge.push_back({src,V});
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
        //un 
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }
    vector<bool>vis(N,false);
    vector<pair<int,int>>B;
    vector<int>dcv(N,N);
    vector<int>low(N,N);
    vector<int>parent(N,-1);
    int t=0;
    for(int i=0;i<N;i++)
    {
        if(vis[i]==false)
        {
 
            DFSUtil(adj,B,parent,low,dcv,vis,i,t);
        }
    }
    for(int i=0;i<B.size();i++)
    {
        cout<<B[i].f << " <-----> "<< B[i].s<<endl;
    }
    //code
    return 0;
}
