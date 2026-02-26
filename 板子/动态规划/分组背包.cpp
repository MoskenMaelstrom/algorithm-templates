// Problem: P1757 通天之分组背包
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1757
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int m,n;
	cin>>m>>n;
	vector adj(101,vector<array<int,2>>(0));//100个组
	for(int i=1;i<=n;i++) {
		int cost,val,kind;
		cin>>cost>>val>>kind;
		adj[kind].push_back( {cost,val} );
	}
	
	vector dp(101,vector<int>(m+1));
	int p=0;
	for(int i=1;i<=100;i++) {
		if (adj[i].size() == 0) continue;
		for(int j=0;j<=m;j++) {
			dp[i][j]=dp[p][j];
			for(int k=0;k<adj[i].size();k++) {
				int cost=adj[i][k][0];
				int val=adj[i][k][1];
				if (j-cost >= 0) dp[i][j]=max(dp[i][j],dp[p][j-cost]+val);
			}
		}
		p=i;
	}
	cout<<dp[p][m];
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









