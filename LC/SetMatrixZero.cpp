/*����һ��m*n�ľ��������һ��Ԫ����0���ͰѸ�Ԫ�����ڵ��к����ϵ�Ԫ��ȫ��Ϊ0��Ҫ��ʹ��ԭ���㷨�� 
��չ�� 
����㷨��ʹ�ö���Ŀռ��� 
һ�ֱȽ�ֱ�ӵ��㷨������O(m,n)�Ŀռ䣬�����ⲻ��һ���õĽⷨ 
ʹ�ü򵥵ĸĽ�������O(m+n)�Ŀռ���������⣬���ǻ�������ѵĽⷨ 
�����ڳ������Ŀռ临�Ӷ��ڽ����������� */
#include<vector>
using namespace std;
class Solution {
public:
	/*���ڿռ�Ҫ���ϸ�����⣬���Կ���ʹ��ʵ�εĿռ䣨��matrix,һ�߲���һ�߱�ǣ�
	����Ҳ���õ�һ�С���һ������¼�������һ����0*/
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