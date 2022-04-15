// A simple representation of graph using STL
#include <bits/stdc++.h>
using namespace std;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	//adj[v].push_back(u);
}


int detectCycle(vector<int> adj[], int s ,int visited[], int recSt[])
{

    visited[s]=1;
    recSt[s]=1;
    for(int u:adj[s])
    {
        if(visited[u]==0 && detectCycle(adj,u,visited,recSt))
                return 1;

        else if(recSt[u]==1)
            return 1;
    }
    recSt[s]=0;
    return 0;
}
int dfs(vector<int> adj[], int v)
{

    int visited[v];
    int recSt[v]; //created recursive stack
	for(int i=0;i<v;i++)
    {
        visited[i]=0;
        recSt[i]=0;
    }

    for(int i=0;i<v;i++)
        if(visited[i]==0)
            if(detectCycle(adj,i,visited,recSt)==1)
                return 1;

    return 0;
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

	int res=dfs(adj,V);
	cout<<"\n\nGraph contains a cycle?: "<<res<<"\n";
	return 0;
}
