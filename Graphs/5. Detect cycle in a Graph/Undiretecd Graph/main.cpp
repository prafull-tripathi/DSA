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


bool detectCycle(vector<int> adj[], int s ,int visited[], int parent)
{

    visited[s]=1;

    for(int u:adj[s])
    {
        if(visited[u]==false)
            if(detectCycle(adj,u,visited,s)==true)
                return true;
        else if(u!=parent)
            return true;
    }
    return false;
}
bool dfs(vector<int> adj[], int v)
{

    int visited[v];
    for(int i=0;i<v;i++)
        visited[i]=0;
    for(int i=0;i<v;i++)
        if(visited[i]==false)
            if(detectCycle(adj,i,visited,-1)==true)
                return true;

    return false;
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

	bool res=dfs(adj,V);
	cout<<"\n\nGraph contains a cycle?: "<<res<<"\n";
	return 0;
}
