#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int dfs(int u,int parent,vector <pair<int,int> > adj[],ll &ans,int N){
	int currentTreeSize=1;
	for (auto p:adj[u]){
		int v=p.first;
		int wt=p.second;
		//Skip the parent node 
		if (v==parent){
			continue;
		}
		int childTreeSize=dfs(v,u,adj,ans,N);
		int edgeContribution=2*min(childTreeSize,N-childTreeSize)*wt;
		ans+=edgeContribution;
		//update the tree size by adding childTree size
		currentTreeSize+=childTreeSize;
	}
	return currentTreeSize;
}
int main(){
	int t;
	cin>>t;
	int n,u,v,w; //where n is total number of nodes, u and v are vertices betwen which there is an edge and w is weight of graph 
	//Graph 
	vector <pair<int,int>> adj[100005]; //becuase in the problem constraints 10^5 nodes are given as constraints
	for (int tc=1;tc<=t;tc++){
	    cin>>n;
		for (int i=1;i<=n;i++){ //reset the adjacency list before each test case
			adj[i].clear(); 
		} 
		//scanning thorugh the edges of the graph
		for (int j=1;j<=(n-1);j++){
			cin>>u>>v>>w;
			adj[u].push_back({v,w});
			adj[v].push_back({u,w});
		}
		//DFS
		long long ans=0;
		dfs(1,-1,adj,ans,n); 
		cout << "Case #" << tc << ": " << ans <<endl;
	}
	return 0;
}