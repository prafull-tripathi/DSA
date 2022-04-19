#include <bits/stdc++.h>
using namespace std;

priority_queue< pair<int,int>, vector <pair<int, int>>, greater<pair<int,int>>> pq;

void addEdge(vector<pair<int,int>> adj[], int u, int v, int wt)
{
	adj[u].push_back(make_pair(v,wt));
	adj[v].push_back(make_pair(u,wt));
}

void PrimsAlgo(vector<pair<int,int>> adj[], int N, int s)
{
    int parent [N];
    int key [N];
    bool mstSet [N];

    for (int i = 0; i < N;i++){
        key [i] = INT_MAX;
        mstSet[i] = false;
    }
    key [s] = 0;
    parent [s] = -1;
    pq.push({0, s});

    for (int count = 0; count < N - 1; count++)
    {
        int u = pq.top().second;
        pq.pop();
        mstSet [u] = true;
        for (auto it: adj [u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet [v] == false && weight < key [v]) {
                parent [v] = u;
                pq.push({key [v], v});
                key [v] = weight;
            }
        }
    }
    for(int i=0;i<N;i++){
        cout<<parent[i]<<" - "<<i<<"\n";
    }
}

int main()
{
	int V;
	cout<<"Total Vertices you want to insert?\n ";
	cin>>V;
	char ch='y';
	int v,u,wt;
	vector<pair<int,int>> adj[V];
	do{
        cout<<"Enter vertex(u) which you want to connect(v) and weight:\n";
        cin>>u>>v>>wt;
        addEdge(adj,u,v,wt);

	}while();

	PrimsAlgo(adj,V,1);
	return 0;
}
