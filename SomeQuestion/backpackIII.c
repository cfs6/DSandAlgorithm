//Backpack III: the item can be selected repeatedly
int backpackIII(int m, int[] array, int[] value){
	if(m < 0||array == nullptr || value == nullptr)
		return 0;
	int n = array.length;
	int[][] dp = new int[n][m+1];
	for(int j = 0; j < m; ++j){
		dp[0][j] = 0;
		int p = 1;
		int max = 0;
		while(p*array[0]<j){
			dp[0][j] = value[0]*p;
			++p;
			if(max < dp[0][j])
				max = dp[0][j];
		}
		dp[0][j] = max;
	}
	for(int i = 0; i < n; ++i)
		dp[i][0] =0;
	for(int i = 1; i < n; ++i){
		for(int j = 1; j < m; ++j){
			int k = 1, maxV = 0;
			dp[i][j] = dp[i-1][j];
			while(array[i]*k <= j){
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-k*array[i]]+value[i]*k);
				++k;
				if(maxV < dp[i][j])
					maxV = dp[i][j];
			}
			dp[i][j] = maxV;
		}
	}
	return dp[n-1][m];
	
}
