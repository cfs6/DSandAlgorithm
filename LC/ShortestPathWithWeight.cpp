/*给定一个由非负整数填充的m x n的二维数组，
现在要从二维数组的左上角走到右下角，请找出路径上的所有数字之和最小的路径。
注意：你每次只能向下或向右移动。*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	/**
	*
	* @param grid int整型vector<vector<>>
	* @return int整型
	*/
	int minPathSum(vector<vector<int> >& grid) {
		int row = grid.size();
		int col = grid[0].size();
		vector<vector<int>> dp(row + 1, vector<int>(col + 1));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < row; ++i)
		{
			dp[i][0] = dp[i - 1][0] + grid[i][0];
		}
		for (int j = 1; j < col; ++j)
		{
			dp[0][j] = dp[0][j - 1] + grid[0][j];
		}
		for (int i = 1; i < row; ++i)
		{
			for (int j = 1; j < col; ++j)
			{
				dp[i][j] = min((dp[i][j - 1] + grid[i][j]), dp[i - 1][j] + grid[i][j]);
			}
		}
		return dp[row - 1][col - 1];
	}
};