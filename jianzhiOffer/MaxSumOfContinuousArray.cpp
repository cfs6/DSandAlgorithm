#include<vector>
#define maxof2(a,b) a>=b?a:b

int MaxSumOfContinuousArray(std::vector<int> pData, int length) {
	if (pData.size() == 0 || length <= 0)
		return 0;
	std::vector<std::vector<int>> maxSum(length, std::vector<int>(length+1));
	for (int i = 0; i < length; ++i) {
		maxSum[i][0] = 0;
		maxSum[i][1] = i;
	}
	for (int j = 1; j <= length; ++j) {
		maxSum[0][j] = pData[0];
	}

	for (int i = 1; i < length; i++) {
		for (int j = 1; j <= length; ++j) {
			if (maxSum[i][j - 1] < 0) {
				maxSum[i][j] = pData[j];
			}
			else
				maxSum[i][j] = maxSum[i][j - 1]+pData[j];
		}
	}
	int maxS = 0;
	for (int m = 0; m < length; ++m) {
		for (int n = 0; n <= length; ++n) {
			maxS = maxof2(maxSum[m][n], maxS);
		}
	}
	return maxS;
}
