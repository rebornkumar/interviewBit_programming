/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/
 
/* The function takes an adjacency list representation of the graph g
    and two integers N and M as specified in the problem statement
    You are required to complete this method. */
stack<int> s;   
vector<int> vv[100001];
void reverse (vector<int> v[100001],int N){
    for(int i=1;i<=N;i++){
        for(int j=0;j<v[i].size();j++){
            int temp=v[i][j];
            vv[temp].push_back(i);
        }
    }
}
 
void fill(int src,bool vis[],vector<int> v[100001]){
    vis[src]=true;
    for(int j=0;j<v[src].size();j++){
        if(vis[ v[src][j] ]==false)
        fill(v[src][j],vis,v);
    }
    s.push(src);
}
void ck(int src,bool vis[]){
    vis[src]=true;
    for(int i=0;i<vv[src].size();i++)
        if(vis[vv[src][i]]==false)
            ck(vv[src][i],vis);
}
int kosaraju(vector<int> v[100001], int N, int M){
    for(int i=1;i<=N;i++)
        vv[i].clear();
 
    bool vis[N+1];
 
    for(int i=1;i<=N;i++)
        vis[i]=false;
 
    for(int i=1;i<=N;i++){
        if(vis[i]==false)
            fill(i,vis,v);
    }
 
    reverse(v,N);
 
    for(int i=1;i<=N;i++)
        vis[i]=false;
 
    int count=0;
    while(!s.empty()){
        int temp=s.top();
        s.pop();
        if(vis[temp]==false){
            count++;
            ck(temp,vis);
        }
    }
    return count;
}
