#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
vector <int> gr[N];
int vis[N],disc[N],low[N],tme=1;
set <int> arti_points;
vector <pair<int,int>> bridges;
void dfs(int cur,int par){
	vis[cur]=1;
	disc[cur]=tme;
	low[cur]=tme; //denotes how much above I can climb in the DFS tree
	int child=0; //calculating number of child of a node
	tme++;
	for (auto x:gr[cur]){
		if (!vis[x]){
			dfs(x,cur);
			//we know low and disc of children
			child++;
			low[cur]=min(low[cur],low[x]);
		//bridges
		if (low[x]>disc[cur]){
			bridges.push_back({cur,x});
		}
		//articulation points
		if (par!=0 && low[x]>=disc[cur]){ //I need to check separately whether root 0 is an articulation point
			arti_points.insert(cur);
		}
	}
		else if (x!=par){ //this means that I have an edge which is visited and it is not its parent, hence it is a backedge
			low[cur]=min(low[cur],disc[x]); //Why disc[x] here and not low[x], this is because x is already visited due to backedge whereas low is something which is calculated after dfs call, I obviously can't make a recursive call to x, do I use disc[x] instead of low[x]
		}
}
	//checking whether root is an articulation point or not
	if (par==0 && child>1){
		arti_points.insert(par);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,m;
	cin>>n>>m;
	//n is number of nodes and m is number of edges
	for (int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	dfs(1,0);
	cout << "The bridge edges are " << endl; 
	for (auto x:bridges){
		cout << x.first << " " <<x.second <<endl;
	}
	for (auto x:arti_points){
		cout << "Articulation points are " << x << ",";
	}
}