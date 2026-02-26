
// 割边 (Bridge)
struct CutE {
	int n;
	vector<vector<int>> adj;
	vector<int> dfn, low;
	int cur;
	vector<pair<int, int>> edge;
	
	CutE() {};
	
	void init(int n) {
		this->n=n;
		adj.assign(n,{});
		dfn.assign(n,-1);
		low.assign(n,-1);
		edge.clear();
		cur=0;
	}
	
	CutE(int n) {init(n);}
	
	void add(int u,int v) {	
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	void dfs(int u, int parent = -1) {
		dfn[u]=low[u]=cur++;
		for(auto v : adj[u]) {
			if (v == parent) continue;
			if (dfn[v] == -1) {
				dfs(v, u);
				low[u]=min(low[u],low[v]);
				if (low[v] > dfn[u]) {
					if (u < v) edge.push_back({u, v});
					else edge.push_back({v, u});
				}
			}	
			else low[u]=min(low[u],dfn[v]);
		}
	}
	
	vector<pair<int, int>> work() {
		cur=0;
		edge.clear();
		for(int i=0;i<n;i++) {
			if (dfn[i] == -1) dfs(i, -1);
		}
		return edge;
	}
};
