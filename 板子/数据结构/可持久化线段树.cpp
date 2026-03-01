//求区间第k小的值
struct PSegTree {
    struct Node {
        int ls,rs,cnt;
    };
    int maxn;
    vector<Node> tr;
    vector<int> root;
    
    PSegTree(int _,int ops) {
        maxn=_;
        tr.reserve(1+ops*(__lg(maxn)+2)); 
        tr.push_back({0,0,0});
        root.push_back(0);
    }
    
    int insert(int prev,int l,int r,int val) {
        int p=tr.size();
        tr.push_back(tr[prev]);
        tr[p].cnt++;
        
        if (l == r) return p;
        int m=l+(r-l)/2;
        if (val <= m) tr[p].ls=insert(tr[prev].ls,l,m,val);
        else tr[p].rs=insert(tr[prev].rs,m+1,r,val);
        return p;
    }
    
    void add(int val) {
        int cur=insert(root.back(),1,maxn,val);
        root.push_back(cur);
    }
    
    int query(int u,int v,int l,int r,int k) {
        if (l == r) return l;
        int m=l+(r-l)/2;
        int c=tr[tr[v].ls].cnt-tr[tr[u].ls].cnt;
        if (k <= c) return query(tr[u].ls,tr[v].ls,l,m,k);
        else return query(tr[u].rs,tr[v].rs,m+1,r,k-c);
    }
};

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	auto b=a;
	ranges::sort(b);
	b.erase(unique(b.begin(),b.end()),b.end());
	PSegTree st(b.size(),n);
	for(int i=0;i<n;i++) st.add(ranges::lower_bound(b,a[i])-b.begin()+1);
	
	while (q--) {
		int l,r,k;
		cin>>l>>r>>k;
		cout<<b[st.query(st.root[l-1],st.root[r],1,b.size(),k)-1]<<"\n";
	}
}
