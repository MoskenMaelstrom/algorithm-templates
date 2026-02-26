	int n;
	cin>>n;
	vector<bool> isp(n+1,1);
	isp[0]=0;
	isp[1]=0;
	for(int i=2;i<=n;i++) {
		if (isp[i] == 0) continue;
		for(int j=i;i*j<=n;j++) {
			isp[i*j]=0;
		}
	}