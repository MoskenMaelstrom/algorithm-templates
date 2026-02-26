
//DAG
int MaxPath(vector<vector<int>>& adj) {
	unordered_map<int,int> dp;
	function<int(int)> dfs=[&](int u) {
	    if (dp.count(u)) return dp[u];
	    int max_len=0;
	    for (int v : adj[u]) {
	        max_len=max(max_len,1+dfs(v));
	    }
	    return dp[u]=max_len;
	};
    int n=adj.size();
    int res=0;
    for (int i=0;i<n;i++) {
        res=max(res,dfs(i));
    }
    return res;
}
