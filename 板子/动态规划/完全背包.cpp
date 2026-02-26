

	// 严格位置依赖
	vector dp(n+1,vector<int>(m+1));
	
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			dp[i][j]=dp[i-1][j];
			if (j-cost[i] >= 0) dp[i][j]=max(dp[i][j],dp[i][j-cost[i]]+val[i]);
		}
	}
	cout<<dp[n][m];
	
	

	// 空间压缩
	vector<int> dp(m+1);
	
	for(int i=1;i<=n;i++) {
		for(int j=cost[i];j<=m;j++) {
			dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
		}
	}
	cout<<dp[m];
	
	
	
	// 可行方案数
	vector<int> dp(m+1);
	dp[0]=1;
	for(int i=1;i<=n;i++) {
		for(int j=cost[i];j<=m;j++) {
			dp[j]+=dp[j-cost[i]];
		}
	}
	cout<<dp[m];
	
	
	
	
	
	
	
	