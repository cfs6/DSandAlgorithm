//给定一些物品数组和一个目标值，问有多少种可以组成目标的组合数，比如给定物品数组 [2,3,6,7] 和目标值 7, 那么就有2种可能：[7] 和 [2, 2, 3]。所以返回2。这道题也可以这样描述：给1，2，5，10硬币无数多个，请问凑80元的方案总数。
int backpackIV(int[] numbers, int target){
	if(numbers == nullptr||target<0)
		return -1;
	int m = target;
	int n = numbers.length;
	int[][] dp = new int[n][m+1];
	for(int i = 0; i <= m; ++i){
		dp[0][i] = 0;
		if(numbers[0]<=i){
			if(i%numbers[0]==0)
				dp[0][i] = 1;
		}
	}
	for(int j = 0; j < n; ++j)
		dp[j][0] = 0;
	for(int i = 1; i < n; ++i){
		for(int j = 1; j <= m; ++j){
			int count = m/numbers[i];
			dp[i][j] = dp[i-1][j];
			while(count != 0){
				dp[i][j] += dp[i - 1][m - count * numbers[i]];
				--count;
			}
		}
	}
	return dp[n-1][m];
}
