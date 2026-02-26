#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

//题意是选择第2k和2k+1的石子，选择丢弃一堆，分另一堆
void solve()
{
	int n=100;
	vector dp(n,vector<int>(n,-1));
	auto sg=[&](this auto &&self,int x,int y) -> int {
		if (x == 1 and y == 1) return 0;
		if (dp[x][y] != -1) return dp[x][y];
		vector<int> app(max(x,y)+1);
		if (x > 1) {
			for(int i=x-1;i>0;i--) app[self(i,x-i)]=1;
		}
		if (y > 1) {
			for(int i=y-1;i>0;i--) app[self(i,y-i)]=1;
		}
		
		for(int i=0;i<=max(x,y);i++) {
			if (app[i] == 0) {
				dp[x][y]=i;
				return i;
			}
		}
	};
	for(int j=0;j<n;j++) cout<<j<<" ";
	cout<<"\n\n"; 
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			dp[i][j]=sg(i,j);
			cout<<dp[i][j]<<" \n"[j == n-1];
		}
	}
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









