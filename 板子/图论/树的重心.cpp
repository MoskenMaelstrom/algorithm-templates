
vector<int> Centroid(const vector<vector<int>>& adj) {
    int n=adj.size();
    vector<int> res;
    vector<int> siz(n,0);
    int maxn=n+1;

    function<void(int,int)> dfs=[&](int u,int fa) {
        siz[u]=1;
        int x=0; 

        for (int v : adj[u]) {
        	if (v == fa) continue;
            dfs(v,u);
            siz[u]+=siz[v];
            x=max(x,siz[v]);
        }

        x=max(x,n-siz[u]);

        if (x < maxn) {
            maxn=x;
            res.clear();
            res.push_back(u);
        } 
        else if (x == maxn) {
            res.push_back(u);
        }
    };
    
    dfs(0,-1);
    return res;
}
