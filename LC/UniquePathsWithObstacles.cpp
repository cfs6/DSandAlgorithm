/*继续思考题目"Unique Paths": 
如果在图中加入了一些障碍，有多少不同的路径？ 
分别用0和1代表空区域和障碍 */

#include<vector>
using namespace std;
class Solution {
public:
	/**
	*
	* @param obstacleGrid int整型vector<vector<>>
	* @return int整型
	*/
	int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
		int row = obstacleGrid.size();
		int col = obstacleGrid[0].size();
		vector<vector<int>> dp(row + 1, vector<int>(col + 1));
		for (int i = 0; i < row; ++i)
		{
			if (obstacleGrid[i][0] == 1)
				break;
			dp[i][0] = 1;
		}
		for (int j = 0; j < col; ++j)
		{
			
			if (obstacleGrid[0][j] == 1)
				break;
			dp[0][j] = 1;
		}
		for (int i = 1; i < row; ++i)
		{
			for (int j = 1; j < col; ++j)
			{
				if (obstacleGrid[i][j] == 1)
				{
					dp[i][j] = 0;
					continue;
				}
				dp[i][j] = (obstacleGrid[i - 1][j] == 1 ? 0 : dp[i - 1][j]) + (obstacleGrid[i][j - 1] == 1 ? 0 : dp[i][j - 1]);
			}
		}
		return dp[row - 1][col - 1];
	}
};