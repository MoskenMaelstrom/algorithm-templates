
//1-based
struct ST {
    #define lg2(n) (63 - __builtin_clzll((long long)(n)))
    int n, B;
    vector<vector<int>> st;
    ST (int n, vector<int> &a): n(n) {
        B = lg2(n) + 2;
        st.assign(B, vector<int>(n + 5, 0));
        for (int i = 1; i <= n; i++) st[0][i] = a[i];
 
        for (int j = 1; j < B; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                st[j][i] = gcd(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
 
    int query(int l, int r) {
        int k = lg2(r - l + 1);
        return gcd(st[k][l], st[k][r - (1 << k) + 1]);
    }
};
