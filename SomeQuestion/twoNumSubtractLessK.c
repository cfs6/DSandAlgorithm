int MaxMatch(int n, int k, int[] weight){
	if(n<=0||k<=0||weight==nullptr)
		return 0;
	int [][]maxMatch = new int[n][k+1];
	for(int i = 0; i < k+1; ++i){
		maxMatch[0][i] = 0;
	}
	for(int i = 0; i < n; ++i){
		maxMatch[i][0] = 0;
	}
	for(int i = 1; i < n; ++i){
		for(int j = 1; j < k+1; ++j){
			maxMatch[i][j] = maxMatch[i-1][j-1];
			if(maxMatch[i-1][j-1] != ((i-1)/2)){
				int singleN = maxMatch[i-1][j-1] - (i-1)/2;
				for(int s = 0; s < j-1; ++s){
					if(abs(weight[j]-weight[j-1])<=k){
						//todo
					}
				}
				for(int s = 0; s < singleN; ++s){
					if(abs(weight[i]-weight[s])<=k){
						++maxMatch[i-1][j-1];	
						break;
					}
				}
			}
		}
	}
	return maxMatch[n-1][k];
}
