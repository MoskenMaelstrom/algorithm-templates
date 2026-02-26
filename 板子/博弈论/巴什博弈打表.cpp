// Problem: Good Luck in CET-4 Everybody!
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=1847
// Memory Limit: 32 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

//经典巴什博弈例题，每人只能拿2的若干次石子
//枚举我们所有取的可能，对面只要有一个必败态，通过mex我们就是必胜的
int mex(set<int> st) {
	for(int i=0;;i++) {
		if (st.find(i) == st.end()) return i;
	}
}

void solve()
{
	int n;
	while (cin>>n) {
		unordered_map<int,int> mp;
		auto sg=[&](auto self,int x) -> int {
			if (mp.count(x)) return mp[x];
			
			set<int> st;
			for(int i=1;i<=x;i<<=1) st.insert(self(self,x-i));
			return mp[x]=mex(st);
		};
		
		for(int i=0;i<100;i++) cout<<sg(sg,i)<<' ';
		// cout<<(sg(sg,n) == 0 ? "Cici\n" : "Kiki\n");
		// cout<<(n%3 == 0 ? "Cici\n" : "Kiki\n");
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}









