#include<bits/stdc++.h>
using namespace std;
 
 
class Graph
{
    int V;
    list<int>*adj;
    void DFS(int src,bool vis[]);
    bool DFSUtil(int src,int parent,bool vis[]);
    public:
    Graph(int V);
    void addEdge(int u,int v);
    bool isTree();
};
Graph::Graph(int N)
{
    this->V=N;
    adj=new list<int>[V];
}
void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Graph::DFS(int src,bool vis[])
{
    vis[src]=true;
    for(auto it=adj[src].begin();it!=adj[src].end();it++)
    {
        if(vis[*it]==false)
        {
            DFS(*it,vis);
        }
    }
}
bool Graph::DFSUtil(int src,int parent,bool vis[])
{
    vis[src]=true;
    for(auto it=adj[src].begin();it!=adj[src].end();it++)
    {
        if(vis[*it]==false)
        {
            if(DFSUtil(*it,src,vis))
            return true;
        }
        else if(*it!=parent)
        {
            return true;
        }
    }
    return false;
}
bool Graph::isTree()
{
    bool *vis=new bool [V];
    memset(vis,false,sizeof(vis));
    DFS(0,vis);
    for(int i=0;i<V;i++)
    {
        if(vis[i]==false)
        return false;
    }
    memset(vis,false,sizeof(vis));
    bool flag=DFSUtil(0,-1,vis);
    return (flag==false);
}
 
int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
 
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
 
    return 0;
}
