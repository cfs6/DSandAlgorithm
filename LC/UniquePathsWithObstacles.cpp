/*����˼����Ŀ"Unique Paths": 
�����ͼ�м�����һЩ�ϰ����ж��ٲ�ͬ��·���� 
�ֱ���0��1�����������ϰ� */

#include<vector>
using namespace std;
class Solution {
public:
	/**
	*
	* @param obstacleGrid int����vector<vector<>>
	* @return int����
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