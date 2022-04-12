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

// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<int> adj[], int V)
{
	for (int v = 0; v < V; ++v) {
		cout << "\n Adjacency list of vertex " << v
			<< "\n head ";
		for (auto x : adj[v])
			cout << "-> " << x;
		printf("\n");
	}
}

// Driver code
int main()
{
	int V = 5;
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
	printGraph(adj, V);
	return 0;
}
