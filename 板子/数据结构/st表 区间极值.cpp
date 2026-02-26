
//1-based
template<typename T, bool isMin>
struct SparseTable{
    int n, m;
    vector<vector<T>> f;
 
    SparseTable() {}
    SparseTable(int n) : n(n), m(__lg(n)), f(m + 1, vector<T>(n + 1)) {}
    SparseTable(const vector<T> &init) : SparseTable((int)init.size()){
        for(int i = 1; i <= n; i++){
            f[0][i] = init[i - 1];
        }
        for(int j = 1; j <= m; j++){
            for(int i = 1; i + (1 << j) - 1 <= n; i++){
                if (isMin) f[j][i] = min(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
                else f[j][i] = max(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
            }       
        }
    }
 
    T query(int l, int r){
        if (l > r){
            if (isMin) return numeric_limits<T>::max() / 10;
            return numeric_limits<T>::min() / 10;
        }
        int len = __lg(r - l + 1);
        if (isMin) return min(f[len][l], f[len][r - (1 << len) + 1]);
        return max(f[len][l], f[len][r - (1 << len) + 1]);        
    }
};
