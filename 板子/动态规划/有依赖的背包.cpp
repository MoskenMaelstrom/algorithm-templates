// Problem: P1064 [NOIP 2006 提高组] 金明的预算方案
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1064
// Memory Limit: 512 MB
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
	int n,m;
	cin>>n>>m;
	vector<int> cost(m+1),val(m+1),kind(m+1);
	for(int i=1;i<=m;i++) {
		cin>>cost[i]>>val[i]>>kind[i];
		val[i]*=cost[i];
	}
	
	vector<bool> king(m+1,0);
	vector adj(m+1,vector<int>(0));//存主件的附件的指针
	
	for(int i=1;i<=m;i++) {
		if (kind[i] == 0) king[i]=1;
		else adj[kind[i]].push_back(i);
	}
	
	
	vector dp(m+1,vector<int>(n+1));
	int p=0;//存上一个主件的指针
	for(int i=1;i<=m;i++) {
		if (!king[i]) continue;	
		for(int j=n;j>=0;j--) {
			dp[i][j]=dp[p][j];
			//要i
			if (j-cost[i] >= 0) dp[i][j]=max(dp[i][j],dp[p][j-cost[i]]+val[i]);
			else continue;
			int k1,k2;
			//如果有附1
			if (adj[i].size() >= 1) {
				k1=adj[i][0];
				if (j-cost[k1]-cost[i] >= 0) dp[i][j]=max(dp[i][j], dp[p][j-cost[k1]-cost[i]]+val[k1]+val[i]);
			}
			//如果有附2
			if (adj[i].size() == 2) {
				k2=adj[i][1];
				if (j-cost[k2]-cost[i] >= 0) dp[i][j]=max(dp[i][j], dp[p][j-cost[k2]-cost[i]]+val[k2]+val[i]);
				if (j-cost[k1]-cost[k2]-cost[i] >= 0) dp[i][j]=max(dp[i][j], dp[p][j-cost[k1]-cost[k2]-cost[i]]+val[k1]+val[k2]+val[i]);
			}
		}
		p=i;
	}
	
	
	cout<<dp[p][n];
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









