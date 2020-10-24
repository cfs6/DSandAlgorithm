/*һ����������m��n��С�ĵ�ͼ�����Ͻǣ���㣬��ͼ�еı�ǡ�start"��λ�ã���
������ÿ�����»������ƶ���������Ҫ�����ͼ�����½ǡ����յ㣬��ͼ�еı�ǡ�Finish"��λ�ã���
�����ж����ֲ�ͬ��·��������ߵ��յ㣿*/
#include<vector>
using namespace std;
class Solution {
public:

	int uniquePaths(int m, int n) {
		if (m == 1 && n == 1)
			return 1;
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		dp[0][0] = 0;
		for (int i = 1; i < m; ++i)
			dp[i][0] = 1;
		for (int j = 1; j<n; ++j)
			dp[0][j] = 1;

		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};