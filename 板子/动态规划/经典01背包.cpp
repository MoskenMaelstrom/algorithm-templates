auto bag=[&]() -> int {
	vector<int> dp(T+1);
	for(int i=0;i<n;i++) {
		for(int j=T;j>=cost[i];j--) {
			dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
		}
	}
	return dp[T];
};



auto bag=[&]() -> int {
	vector dp(n+1,vector<int>(T+1));
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=T;j++) {
			if (j-cost[i] < 0) dp[i][j]=dp[i-1][j];	
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-cost[i]]+val[i]);
		}
	}
	return dp[n][T];
};