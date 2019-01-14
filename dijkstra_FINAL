#include<bits/stdc++.h>
using namespace std;
#define INF 1000000
#define ll long long
#define f first
#define s second
void dijkstra( vector<vector<pair<ll,ll>>>graph,vector<ll>&dist,ll source,ll N)
{
    vector<bool>visited(N,false);
    dist[source]=0;
    priority_queue<pair<ll,ll>>que;
    que.push({0,source});
    while(que.size()!=0)
    {
        pair<ll,ll>myPair = que.top();
        que.pop();
        ll U = myPair.second;
       // ll D = myPair.f;
        if(visited[U])continue;
        visited[U] = true;
        for(ll i=0;i<graph[U].size();i++)
        {
            ll V = graph[U][i].f;
            ll W = graph[U][i].s;
            if(visited[V]==false&& dist[U] + W < dist[V])
            {
                dist[V] = dist[U] + W;
                que.push({-dist[V],V});
            }
        }
    }
    return ;
}
int main()
{
    //code starts here
    ll N,M,source;
    cin>>N>>M>>source;
    vector<vector<pair<ll,ll>>>adj(N);
    ll X,Y,Z;
    for(ll i=0;i<M;i++)
    {
        cin>>X>>Y>>Z;
        //directed graph and 0 based indexing
        adj[X].push_back({Y,Z});
    }
 
    vector<ll> sol(N,INF);
    dijkstra(adj,sol,source,N);
    for(ll i=0;i<N;i++)
    {
        cout<<sol[i]<<" ";
    }
    //code ends here
    return 0;
}
