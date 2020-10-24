#include<vector>
using namespace std;
class Solution {
public:
	/**
	*
	* @param n int整型
	* @return int整型vector<vector<>>
	*/
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n));
		if (n < 1)
			return res;
		int index = 1, rowStart = 0, colStart = 0, rowEnd = n - 1, colEnd = n - 1;
		while (index <= (n*n))
		{
			for (int i = colStart; i <= colEnd; ++i)
			{
				res[rowStart][i] = index++;
			}
			for (int i = rowStart + 1; i <= rowEnd; ++i)
			{
				res[i][colEnd] = index++;
			}
			for (int i = colEnd - 1; i >= colStart; --i)
			{
				res[rowEnd][i] = index++;
			}
			for (int i = rowEnd - 1; i > rowStart; --i)
			{
				res[i][colStart] = index++;
			}
			rowStart++;
			colStart++;
			rowEnd--;
			colEnd--;
		}
		return res;
	}
};