#include <bits/stdc++.h>
using namespace std;

priority_queue< pair<int,int>, vector <pair<int, int>>, greater<pair<int,int>>> pq;

//void addEdge(vector<pair<int,int>> adj[], int u, int v, int wt)
//{
//	adj[u].push_back(make_pair(v,wt));
//	adj[v].push_back(make_pair(u,wt));
//}

void DjikstraAlgo(vector<pair<int,int>> adj[], int n, int s)
{
 //priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int> > > pq;// min-heap; In pair => (dist,from)
    vector<int> distTo(n+1, INT_MAX); // 1-indexed array for calculating shortest paths;
    distTo[s] = 0;
    pq.push(make_pair(0,s)); // (dist, from)
    while( !pq.empty())
    {
        int dist = pq.top().first;
        cout<<"Distance: "<<dist<<"\n";
        int prev = pq.top().second;
        cout<<"prev: "<<prev<<"\n";
        pq.pop();

        for(auto it: adj[prev])
        {
            int next = it.first;
            cout<<"next: "<< next<<"\n";
            int nextDist= it.second;
            cout<<"nextDist: "<<nextDist<<"\n";
            if( distTo[next]>dist + nextDist)
            {
                distTo[next] = distTo[prev]+ nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<"Distance of "<<s<<" from "<<i<<" is: "<<" : ";
        cout<<distTo[i]<<"\n";
    }
}

int main()
{
	int V,e;
	cout<<"Total Vertex and Edges you want to insert?\n ";
	cin>>V>>e;
	int i;
	int v,u,wt;
	vector<pair<int,int>> adj[V+1];
	for(i=0;i<e;i++){
        cout<<"Enter vertex(u) which you want to connect(v) and weight:\n";
        cin>>u>>v>>wt;
        //addEdge(adj,u,v,wt);
        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));

	}
    int s;
    cout<<"source point? ";
    cin>>s;
	PrimsAlgo(adj,V,s);
	return 0;
}
