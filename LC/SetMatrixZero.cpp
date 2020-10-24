/*给定一个m*n的矩阵，如果有一个元素是0，就把该元素所在的行和列上的元素全置为0，要求使用原地算法。 
拓展： 
你的算法有使用额外的空间吗？ 
一种比较直接的算法是利用O(m,n)的空间，但是这不是一个好的解法 
使用简单的改进可以在O(m+n)的空间解决这个问题，但是还不是最佳的解法 
你能在常量级的空间复杂度内解决这个问题吗？ */
#include<vector>
using namespace std;
class Solution {
public:
	/*对于空间要求严格的问题，可以考虑使用实参的空间（即matrix,一边查找一边标记）
	或者也可用第一行、第一列做记录，最后再一起置0*/
	void setZeroes(vector<vector<int> > &matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (0 == matrix[i][j])
				{
					for (int m = 0; m < cols; ++m)
					{
						if (0 != matrix[i][m])
						{
							matrix[i][m] = -1;
						}
					}
					for (int n = 0; n < rows; ++n)
					{
						if (0 != matrix[n][j])
						{
							matrix[n][j] = -1;
						}
					}
				}
			}
		}
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (-1 == matrix[i][j])
					matrix[i][j] = 0;
			}
		}
	}
};