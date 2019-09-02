//backpack II
int backpack(int m, int[] array, int[] value){
	if(m<0||array==nullptr||value==nullptr)
		return 0;
	int n = array.size();
	int[][] dp = new int[n][m+1];
	for(int i = 0; i < n; ++i){
		dp[i][0] == 0;
	}
	for(int j = 0; j < m; ++j){
		if(value[0]<j)
			dp[0][j] = value[0];
	}
	for(int i = 1; i < n; ++i){
		for(int j = 1; j <= m; ++j){
			if(j=>array[i]){
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-array[i]]+value[i])
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n-1][m];
}
