
vector<vector<int>> fa;
vector<int> depth;
void build(const vector<vector<int>>& adj, int root) {
	int n=adj.size();
    int m = log2(n) + 1;
    fa.assign(m + 1, vector<int>(n, -1));
    depth.assign(n, -1);
    
    queue<int> q;
    q.push(root);
    depth[root] = 0;
    fa[0][root] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                fa[0][v] = u;
                q.push(v);
            }
        }
    }
    
    for (int k = 1; k <= m; k++) {
        for (int u = 0; u < n; u++) {
            if (fa[k-1][u] != -1) {
                fa[k][u] = fa[k-1][fa[k-1][u]];
            } else {
                fa[k][u] = -1;
            }
        }
    }
}

int lift(int u, int target) {
    int dif = depth[u] - target;
    int k = 0;
    
    while (dif > 0) {
        if (dif & 1) {
            u = fa[k][u];
        }
        dif >>= 1;
        k++;
    }
    return u;
}

int query(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    u = lift(u, depth[v]);
    if (u == v) return u;
    
    int m = fa.size() - 1;
    for (int k = m; k >= 0; k--) {
        if (fa[k][u] != fa[k][v]) {
            u = fa[k][u];
            v = fa[k][v];
        }
    }
    
    return fa[0][u];
}

int dist(int u, int v) {
    return depth[u]+depth[v]-2*depth[query(u,v)];
}
