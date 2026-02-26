#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int mod;
struct HLD
{
    int n, root;
    vector<int> top, son, siz, dep, dfn, pos, fa;
    vector<vector<int>> g;
    int cur;
    HLD(int n, int root) : n(n), root(root)
    {
        init();
    }
    void init()
    {
        g.assign(n + 1, {});
        top.assign(n + 1, 0);
        fa.assign(n + 1, 0);
        son.assign(n + 1, 0);
        pos.assign(n + 1, 0);
        dep.assign(n + 1, 0);
        dfn.assign(n + 1, 0);
        siz.assign(n + 1, 0);
        dep[0] = -1;
        cur = 1;
    }
    void add(int u, int v)
    {
        g[u].pb(v);
        g[v].pb(u);
    }
    void dfs1(int u, int f)
    {
        fa[u] = f, dep[u] = dep[f] + 1, siz[u] = 1;
        for (auto v : g[u])
        {
            if (v == f)
                continue;
            dfs1(v, u);
            siz[u] += siz[v];
            if (siz[v] > siz[son[u]])
                son[u] = v;
        }
    }
    void dfs2(int u, int ftop)
    {
        dfn[u] = cur, pos[cur] = u, top[u] = ftop;
        cur++;
        if (son[u])
            dfs2(son[u], ftop);
        for (auto v : g[u])
        {
            if (v == son[u] || v == fa[u])
                continue;
            dfs2(v, v);
        }
    }
    void work()
    {
        dfs1(root, 0);
        dfs2(root, root);
    }
    int lca(int u, int v)
    {
        while (top[u] != top[v])
        {
            if (dep[top[u]] > dep[top[v]])
                u = fa[top[u]];
            else
                v = fa[top[v]];
        }
        return dep[u] > dep[v] ? v : u;
    }
};
struct Info
{
    int sum;
    int size;
    Info() : sum(), size(0) {};
    Info(int value) : sum(value), size(1) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.sum = sum + other.sum;
        res.sum %= mod;
        if (res.sum < 0)
            res.sum += mod;
        res.size = size + other.size;
        return res;
    }
};
struct SegTree
{
    int n;
    vector<int> tag;
    vector<Info> info;
    SegTree(int _n) : n(_n), tag(4 * _n), info(4 * n) {};
    void pull(int p) // 更新上移
    {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void add(int p, int v)
    {
        tag[p] += v;
        info[p].sum += v * info[p].size;
        info[p].sum %= mod;
        if (info[p].sum < 0)
            info[p].sum += mod;
    }
    void push(int p) // 懒标记下放
    {
        add(p << 1, tag[p]);
        add(p << 1 | 1, tag[p]);
        tag[p] = 0;
    }
    // 区间查询[x,y)
    Info query(int p, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
            return {};
        if (l >= x && r <= y)
        {
            return info[p];
        }
        int mid = l + r >> 1;
        push(p);
        return (query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid, r, x, y));
    };
    Info query(int x, int y)
    {
        return query(1, 0, n, x, y);
    };
    // 区间修改[x,y)
    void rangeAdd(int p, int l, int r, int x, int y, int v)
    {
        if (l >= y || r <= x)
            return;
        if (l >= x && r <= y)
        {
            return add(p, v);
        }
        int mid = l + r >> 1;
        push(p);
        rangeAdd(p << 1, l, mid, x, y, v);
        rangeAdd(p << 1 | 1, mid, r, x, y, v);
        pull(p);
    };
    void rangeAdd(int x, int y, int v)
    {
        rangeAdd(1, 0, n, x, y, v);
    }
    // 单点修改
    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            info[p] = v;
            return;
        }
        int mid = l + r >> 1;
        push(p);
        if (x < mid)
        {
            modify(p << 1, l, mid, x, v);
        }
        else
        {
            modify(p << 1 | 1, mid, r, x, v);
        }
        pull(p);
    }
    void modify(int x, int v)
    {
        modify(1, 0, n, x, Info(v));
    }
};
void solve()
{
    int n, m, r;
    cin >> n >> m >> r >> mod;
    HLD g(n, r);
    SegTree sum(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g.add(u, v);
    }
    g.work();
    for (int i = 1; i <= n; i++)
    {
        sum.modify(g.dfn[i], a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int u, v, w;
            cin >> u >> v >> w;
            int l, r;
            while (g.top[u] != g.top[v])
            {
                if (g.dep[g.top[u]] > g.dep[g.top[v]])
                {
                    r = g.dfn[u], l = g.dfn[g.top[u]];
                    sum.rangeAdd(l, r + 1, w);
                    u = g.fa[g.top[u]];
                }
                else
                {
                    r = g.dfn[v], l = g.dfn[g.top[v]];
                    sum.rangeAdd(l, r + 1, w);
                    v = g.fa[g.top[v]];
                }
            }
            l = min(g.dfn[v], g.dfn[u]), r = max(g.dfn[v], g.dfn[u]);
            sum.rangeAdd(l, r + 1, w);
        }
        else if (op == 2)
        {
            int u, v;
            cin >> u >> v;
            int ans = 0;
            int l, r;
            while (g.top[u] != g.top[v])
            {
                if (g.dep[g.top[u]] > g.dep[g.top[v]])
                {
                    r = g.dfn[u], l = g.dfn[g.top[u]];
                    ans += sum.query(l, r + 1).sum;
                    ans %= mod;
                    u = g.fa[g.top[u]];
                }
                else
                {
                    r = g.dfn[v], l = g.dfn[g.top[v]];
                    ans += sum.query(l, r + 1).sum;
                    ans %= mod;
                    v = g.fa[g.top[v]];
                }
            }
            l = min(g.dfn[v], g.dfn[u]), r = max(g.dfn[v], g.dfn[u]);
            ans += sum.query(l, r + 1).sum;
            cout << ans % mod << '\n';
        }
        else if (op == 3)
        {
            int u, w;
            cin >> u >> w;
            int l = g.dfn[u], r = g.dfn[u] + g.siz[u] - 1;
            sum.rangeAdd(l, r + 1, w);
        }
        else
        {
            int u;
            cin >> u;
            int l = g.dfn[u], r = g.dfn[u] + g.siz[u] - 1;
            cout << sum.query(l, r + 1).sum % mod << '\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}