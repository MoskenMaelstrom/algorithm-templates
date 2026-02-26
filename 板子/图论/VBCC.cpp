
struct VBCC {
    int n;
    vector<vector<array<int,2>>> adj;
    vector<array<int,2>> edge;
    vector<int> dfn,low,bel;
    vector<int> stk;
    vector<int> vis;
    int cur,cnt;

    VBCC() {};

    void init(int n) {
        this->n=n;
        adj.assign(n,{});
        edge.clear();
        dfn.assign(n,-1);
        low.assign(n,-1);
        vis.clear();
        stk.clear();
        cur=cnt=0;
    }

    VBCC(int n) {
        init(n);
    }

    void add(int u,int v) {
        adj[u].push_back({v,(int)edge.size()});
        adj[v].push_back({u,(int)edge.size()});
        edge.push_back({u,v});
    }

    void dfs(int u) {
        dfn[u]=low[u]=cur++;
        for (auto [v,pos] : adj[u]) {
            if (vis[pos]) continue;
            vis[pos]=1;
            stk.push_back(pos);
            if (dfn[v] == -1) {
                dfs(v);
                low[u]=min(low[u],low[v]);
                if (low[v] >= dfn[u]) {
                    int y;
                    do {
                        y = stk.back();
                        bel[y] = cnt;
                        stk.pop_back();
                    } while (y != pos);
                    cnt++;
                }
            }
            else low[u]=min(low[u],dfn[v]);
        }
    }

    vector<int> work() {
        bel.assign(edge.size(),-1);
        vis.assign(edge.size(),0);
        for (int i=0;i<n;i++) {
            if (dfn[i] == -1) dfs(i);
        }
        return bel;
    }
    
    vector<set<int>> getEdge() {
    	work();
	    vector<set<int>> E(cnt);
	    for(int i=0;i<edge.size();i++) {
	    	if (bel[i] == -1) continue;
	        auto [u,v]=edge[i];
	        E[bel[i]].insert(i);
	    }
	    return E;
    }
};
