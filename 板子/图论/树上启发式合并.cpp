
//1-based
vector<int> c(n+1);//每个节点的颜色
vector<int> ans(n+1),cnt(n+1),siz(n+1),fa(n+1),son(n+1);
int diff=0,flag=0;
function<void(int,int)> get_info=[&](int u,int f)
{
    fa[u]=f;
    siz[u]=1;
    for (auto v : adj[u]) {
        if (v == f) continue;
        get_info(v,u);
        siz[u]+=siz[v];
        if (siz[v] > siz[son[u]]) son[u]=v;
    }
};
get_info(1,0);

function<void(int,int,int)> count=[&](int u,int f,int val) {
    cnt[c[u]]+=val;
    if (cnt[c[u]] == 0) diff--;
    else if (cnt[c[u]] == 1) diff++;
    for (auto v : adj[u]) {
        if (v == f or v == flag) continue;
        count(v,u,val);
    }
};

function<void(int,int,bool)> dfs=[&](int u,int f,bool ok) {
    for (auto v : adj[u]) {
        if (v == f or v == son[u]) continue;
        dfs(v,u,0);
    }
    if (son[u]) dfs(son[u],u,1),flag=son[u];
    count(u,f,1);
    ans[u]=diff;
    flag=0;
    if (ok == 0) {
        count(u,f,-1);
        diff=0;
    }
};
dfs(1,0,0);
