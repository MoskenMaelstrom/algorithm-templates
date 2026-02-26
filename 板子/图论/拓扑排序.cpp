
//对DAG拓扑排序
vector<int> topo(vector<vector<int>>& adj) {
	int n=adj.size();
	vector<int> deg(n);
	for(int u=0;u<n;u++) {
		for(auto v : adj[u]) deg[v]++;
	}
	
	queue<int> q;
	for(int i=0;i<n;i++) {
		if (deg[i] == 0) q.push(i);
	}
	
	vector<int> order;
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		order.push_back(u);
		
		for(auto v : adj[u]) {
			deg[v]--;
			if (deg[v] == 0) q.push(v);
		}
	}
	
	return order;
}
