/*一个机器人在m×n大小的地图的左上角（起点，下图中的标记“start"的位置）。
机器人每次向下或向右移动。机器人要到达地图的右下角。（终点，下图中的标记“Finish"的位置）。
可以有多少种不同的路径从起点走到终点？*/
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