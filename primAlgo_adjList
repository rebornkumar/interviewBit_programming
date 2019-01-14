#include<bits/stdc++.h>
using namespace std;
#define INF 10000000
#define f first
#define s second
void printMST(vector<vector<pair<int,int>>>graph,vector<int>parent,int N)
{
    for(int i=1;i<N;i++)
    {
        cout<<parent[i]<<"  "<<i<<"  "<<graph[i][parent[i]].s<<endl;
    }
    return ;
}
 
void helper(vector<vector<pair<int,int>>>graph,int N)
{
    priority_queue<pair<int,int>>que;
    vector<int>key(N,INF);
    key[0]=0;
    que.push({0,0});
    set<int>S;
    vector<int>parent(N,-1);
    while(S.size()!=N)
    {
        pair<int,int>myPair=que.top();
        que.pop();
        int u=myPair.s;
        S.insert(u);
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i].f;
            int w=graph[u][i].s;
            if(S.find(v)==S.end()&&key[v]>w)
            {
                parent[v]=u;
                key[v]=w;
                que.push({-w,v});
            }
        }
    }
    printMST(graph,parent,N);
}
 
int main()
{
    //code starts here
    int N,M;
    cin>>N>>M;
    int X,Y,W;
    vector<vector<pair<int,int>>>adj(N);
    for(int i=0;i<M;i++)
    {
        cin>>X>>Y>>W;
        //undirected weighted
        adj[X].push_back({Y,W});
        adj[Y].push_back({X,W});
    }
    helper(adj,N);
 
 
 
 
    //code ends here
    return 0;
}
