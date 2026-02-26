
//强联通分量 Strong Connected Conponent
struct SCC {
	int n;
	vector<vector<int>> adj;
	vector<int> dfn,low,bel,stk;
	int cur,cnt;
	SCC() {};
	
	void init(int n) {
		this->n=n;
		adj.assign(n,{});
		dfn.assign(n,-1);
		low.assign(n,-1);
		bel.assign(n,-1);
		stk.clear();
		cur=cnt=0;
	}
	
	SCC(int n) {init(n);}
	
	void add(int u,int v) {	
		adj[u].push_back(v);
	}
	
	void dfs(int x) {
		dfn[x]=low[x]=cur++;
		stk.push_back(x);
		for(auto y : adj[x]) {
			if (dfn[y] == -1) {
				dfs(y);
				low[x]=min(low[x],low[y]);
			}	
			else if (bel[y] == -1){
				low[x]=min(low[x],dfn[y]);
			}
		}
		
		if (dfn[x] == low[x]) {
			int y;
			do {
				y=stk.back();
				bel[y]=cnt;
				stk.pop_back();
			} while (y != x);
			cnt++;
		}
	}
	
	vector<int> work() {
		for(int i=0;i<n;i++) {
			if (dfn[i] == -1) dfs(i);
		}
		return bel;
	}
	
	vector<vector<int>> getDAG() {
		work();
		vector dag(cnt,vector<int>(0));
		for(int u=0;u<n;u++) {
			for(auto v : adj[u]) {
				if (bel[u] != bel[v]) dag[bel[u]].push_back(bel[v]);
			}
		}
		for(int i=0;i<cnt;i++) {
			ranges::sort(dag[i]);
			dag[i].erase(unique(dag[i].begin(),dag[i].end()),dag[i].end());
		}
		return dag;
	}
};
