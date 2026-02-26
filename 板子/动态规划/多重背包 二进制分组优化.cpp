// Problem: P1776 宝物筛选
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1776
// Memory Limit: 125 MB
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
	vector<array<int,2>> gra;
	for(int i=1;i<=n;i++) {
		int val,cost,num;
		cin>>val>>cost>>num;
		for(int i=0;num-(1<<i)>=0;i++) {
			int k=(1<<i);
			gra.push_back({cost*k,val*k});
			num-=k;
		}
		if (num != 0) gra.push_back({cost*num,val*num});
	}
	
	n=gra.size();
	vector<int> dp(m+1);
	for(int i=0;i<n;i++) {
		for(int j=m;j>=gra[i][0];j--) {
			dp[j]=max(dp[j],dp[j-gra[i][0]]+gra[i][1]);
		}
	}
	cout<<dp[m];
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









