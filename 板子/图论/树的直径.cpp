	auto bfs=[&](int s) {
		vector<int> dis(n,-1);
	    queue<int> q;
	    q.push(s);
	    dis[s] = 0;
	    
	    while (!q.empty()) {
	        int u = q.front();
	        q.pop();
	        
	        for (auto v : adj[u]) {
	            if (dis[v] == -1) {
	                dis[v]=dis[u]+1;
	                q.push(v);
	            }
	        }
	    }
	    return ranges::max_element(dis)-dis.begin();
	};
	
	int s = bfs(0);
	int t = bfs(s);