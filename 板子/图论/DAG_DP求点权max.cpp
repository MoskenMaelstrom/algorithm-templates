
//dag_dp算点权max
//从s到某点路径上的最大点权和
const int inf=1e18;
vector<int> DAG_DP(vector<vector<int>> adj,vector<int> w,int s) {
	int n=adj.size();
	vector<int> deg(n,0);
	for(int u=0;u<n;u++) {
		for(int v : adj[u]) deg[v]++;
	}
	
	queue<int> q;
	for(int i=0;i<n;i++) {
		if (deg[i] == 0) q.push(i);
	}
	
	vector<int> dp(n,-inf);
	dp[s]=w[s];
	
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		
		for(int v : adj[u]) {
			if (dp[u] != -inf) dp[v]=max(dp[v],dp[u]+w[v]);
			deg[v]--;
			if (deg[v] == 0) q.push(v);
		}
	}
	
	return dp;
}
