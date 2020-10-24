/*给出一个整数n，返回n皇后问题的所有摆放方案的个数 */
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	/**
	*
	* @param n int整型
	* @return int整型
	*/
	bool isValid(vector<string>& res, int n, int col, int row)
	{
		for (int i = 0; i < row; ++i)
		{
			if (res[i][col] == 'Q')
				return false;
		}
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
		{
			if (res[i][j] == 'Q')
				return false;
		}
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
		{
			if (res[i][j] == 'Q')
				return false;
		}
		return true;
	}

	void dfs(vector<vector<string>>& res, vector<string>& cur, int n, int row)
	{
		if (row == n)
		{
			res.push_back(cur);
			return;
		}
		for (int i = 0; i < n; ++i)
		{
			if (isValid(cur, n, i, row))
			{
				cur[row][i] = 'Q';
				dfs(res, cur, n, row + 1);
				cur[row][i] = '.';
			}
		}

	}

	int totalNQueens(int n) {
		vector<vector<string>> res;
		vector<string> cur(n, string(n,'.'));
		dfs(res, cur, n, 0);
		return res.size();
	}
};
