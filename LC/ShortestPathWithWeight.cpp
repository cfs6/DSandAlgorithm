/*����һ���ɷǸ���������m x n�Ķ�ά���飬
����Ҫ�Ӷ�ά��������Ͻ��ߵ����½ǣ����ҳ�·���ϵ���������֮����С��·����
ע�⣺��ÿ��ֻ�����»������ƶ���*/
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	/**
	*
	* @param grid int����vector<vector<>>
	* @return int����
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