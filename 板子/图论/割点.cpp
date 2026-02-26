
// 割点 (Articulation Point)
struct CutV {
	int n;
	vector<vector<int>> adj;
	vector<int> dfn,low;
	vector<bool> flag;
	int cur;
	
	CutV() {};
	
	void init(int n) {
		this->n=n;
		adj.assign(n,{});
		dfn.assign(n,-1);
		low.assign(n,-1);
		flag.assign(n,0);
		cur=0;
	}
	
	CutV(int n) {init(n);}
	
	void add(int u,int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	void dfs(int u,int fa=-1) {
		dfn[u]=low[u]=cur++;
		int cnt=0;
		for(auto v : adj[u]) {
			if (v == fa) continue;
			if (dfn[v] == -1) {
				cnt++;
				dfs(v,u);
				low[u]=min(low[u],low[v]);
				if (fa != -1 and low[v] >= dfn[u]) flag[u]=1;
			}
			else low[u]=min(low[u],dfn[v]);
		}
		if (fa == -1 and cnt > 1) flag[u]=1;
	}
	
	vector<bool> work() {
		cur=0;
		for(int i=0;i<n;i++) {
			if (dfn[i] == -1) dfs(i,-1);
		}
		return flag;
	}
};
