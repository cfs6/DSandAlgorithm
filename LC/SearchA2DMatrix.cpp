
/*请写出一个高效的在m*n矩阵中判断目标值是否存在的算法，矩阵具有如下特征： 
每一行的数字都从左到右排序 
每一行的第一个数字都比上一行最后一个数字大 */
#include<vector>
using namespace std;

class Solution {
public:
	/**
	*
	* @param matrix int整型vector<vector<>>
	* @param target int整型
	* @return bool布尔型
	*/
	bool searchMatrix(vector<vector<int> >& matrix, int target) {
		
		int cols = matrix[0].size();
		int rows = matrix.size();
		if (rows == 1 && cols == 1)
		{
			if (matrix[rows - 1][cols - 1] == target)
				return true;
			else
				return false;
		}
		if (target<matrix[0][0] || target>matrix[rows - 1][cols - 1])
			return false;
		int startIndex = 0;
		int endIndex = rows-1;
		
		while (endIndex-1 > startIndex)
		{
			int midIndex = (endIndex - startIndex) / 2 + startIndex;
			if (target == matrix[midIndex][0] || target == matrix[startIndex][0] ||
				target == matrix[endIndex][0])
				return true;
			if (target < matrix[midIndex][0] && matrix[startIndex][0] < target)
			{
				endIndex = midIndex;
			}
			else
			{
				startIndex = midIndex;
			}
		}
		int targetRow = startIndex;
		int begin = 0, end = cols - 1;
		while (end > begin)
		{
			int mid = (begin - end) / 2 + begin;
			if (target == matrix[targetRow][begin] || target == matrix[targetRow][mid]
				|| target == matrix[targetRow][end])
				return true;
			if (target > matrix[targetRow][begin] && target < matrix[targetRow][mid])
			{
				end = mid - 1;
			}
			else
			{
				begin = mid + 1;
			}
		}
		return false;
	}
};