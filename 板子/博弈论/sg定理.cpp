#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;	
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

//画线博弈
//类似于一堆石子不断分开
int mex(set<int> st) {
	for(int i=0;;i++) {
		if (st.find(i) == st.end()) return i;
	}
}

void solve()
{
	unordered_map<int,int> mp;
	mp[0]=0,mp[1]=0,mp[2]=1,mp[3]=1;
	auto sg=[&](auto self,int x) -> int {
		if (mp.count(x)) return mp[x];
		set<int> st;
		for(int i=0;i<=x-2;i++) {
			st.insert(self(self,i)^self(self,x-2-i));
		}
		
		return mp[x]=mex(st);
	};
	
	for(int i=0;i<=1000;i++) cout<<sg(sg,i)<<",";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}









