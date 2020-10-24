
/*��д��һ����Ч����m*n�������ж�Ŀ��ֵ�Ƿ���ڵ��㷨������������������� 
ÿһ�е����ֶ����������� 
ÿһ�еĵ�һ�����ֶ�����һ�����һ�����ִ� */
#include<vector>
using namespace std;

class Solution {
public:
	/**
	*
	* @param matrix int����vector<vector<>>
	* @param target int����
	* @return bool������
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