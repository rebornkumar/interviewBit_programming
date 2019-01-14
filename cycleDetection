#include<bits/stdc++.h>
using namespace std;
// FOR UNDIRECTED GRAPH BUT WE HAVE TO VISIT EVERY EDGE ONCE ONLY X--->Y HAVE PARENT
// X THEN IF WE CHECK FOR Y--->X IT WILL RETURN SAME PARENT MAKING YOU BELIEVE THERE IS
// LOOP IN X---->Y---->X
int find(vector<int>&parent,int X)
{
	if(parent[X]==-1)
	return X;
	return find(parent,parent[X]);
}
void join(vector<int>&parent,int X,int Y)
{
	int pX=find(parent,X);
	int pY=find(parent,Y);
	parent[pX]=pY;
	return;
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
	//	adj[Y].push_back(X);
	}
 
	vector<int>parent(N,-1);
	bool flag=false;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<adj[i].size();j++)
		{
			int V=adj[i][j];
			X=find(parent,i);
			Y=find(parent,V);
			if(X==Y)
			{
				flag=true;
				break;
			}
			join(parent,X,Y);
		}
		if(flag)
		break;
	}
	if(flag)
	cout<<"isCyclic"<<endl;
	else
	cout<<"isLinear"<<endl;
	//code
	return 0;
}
