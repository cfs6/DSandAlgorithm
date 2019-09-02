//Mutiple backpack
int mutipleBackpack(int[] weight, int[] value, int array[], int m){
	if(m<0||weight==nullptr||value==nullptr||array==nullptr)
		return -1;
	int n = array.length;
	int[][] dp = new int[n][m+1];
   for(int i = 0; i < n; ++i){
	   dp[i][0] = 0;
   }	
   for(int j = 0; j < m+1; ++j){
	   int k = min(j/weight[0], array[0]);
	   dp[0][j] = k * value[0];
   }
   for(int i = 1; i < n; ++i){
	   for(int j = 1; j <= m; ++j){
		   int kmax = min(j/weight[i], array[i]);
		   dp[i][j] = dp[i-1][j];
		   int maxValue = 0;
		   int k = 0;
		   while(k*weight[i]<=j&&k<kmax){
			   dp[i][j] = max(dp[i-1][j], dp[i-1][j-k*weight[i]]+k*value[i]);
			   if(maxValue < dp[i][j])
				   maxValue = dp[i][j];
			   ++k;
		   }
		   dp[i][j] = maxValue;
		   maxValue = 0;
	   }
   }
   return dp[n-1][m];
}
