class TreeAnc {
private:
    vector<vector<int>> anc;
    int maxLog;
    vector<int> depth;

public:
    TreeAnc(vector<vector<int>>& adj, int root = 1) {
        int n = adj.size();
        maxLog = __lg(n)+1;
        anc.resize(maxLog, vector<int>(n, -1));
        
        //bfs
        depth.assign(n,-1);
        vector<int> st;
        st.push_back(root);
        depth[root] = 0;
        while (!st.empty()) {
            int node = st.back();
            st.pop_back();
            for (int son : adj[node]) {
                if (depth[son] == -1) {
                    depth[son] = depth[node] + 1;
                    anc[0][son] = node;
                    st.push_back(son);
                }
            }
        }

        for (int i = 1; i < maxLog; i++) {
            for (int j = 0; j < n; j++) {
                if (anc[i-1][j] != -1) {
                    anc[i][j] = anc[i-1][anc[i-1][j]];
                }
            }
        }
    }

    int query(int p, int step) {
        if (step < 0) return -1;
        for (int i = 0; i < maxLog; i++) {
            if (step & (1ll << i)) {
                p = anc[i][p];
                if (p == -1) break;
            }
        }
        return p;
    }
    
    //0-based
    int deep(int p) {
    	return depth[p];
    }
};