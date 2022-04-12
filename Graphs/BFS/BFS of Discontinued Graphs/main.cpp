// A simple representation of graph using STL
#include <bits/stdc++.h>
using namespace std;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}


void bfs(vector<int> adj[], int s ,int visited[])
{
//	int visited[v];
//	for(int i=0;i<v;i++)
//        visited[i]=0;

    queue<int>q;
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:adj[u])
        {
            if(visited[v]==0)
            {

                q.push(v);
                visited[v]=1;
            }
        }
    }
}
void bfsDisContinued(vector<int> adj[], int v)
{
    int visited[v];
	for(int i=0;i<v;i++)
        visited[i]=0;

    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
            bfs(adj,i,visited);
    }
}

// Driver code
int main()
{
	int V;
	cout<<"Total Vertices you want to insert?\n ";
	cin>>V;
	char ch='y';
	int v,u;
	vector<int> adj[V];
	do{
        cout<<"Enter vertex(u) which you want to connect(v):\n";
        cin>>u>>v;
        addEdge(adj,u,v);
        cout<<"Want to connect more??\n";
        cin>>ch;
	}while(ch!='n');

	bfsDisContinued(adj,V);
	return 0;
}