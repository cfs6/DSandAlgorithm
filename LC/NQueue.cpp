/*给出一个整数n，返回n皇后问题的所有摆放方案 */
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	//尽量不要首先考虑作太多转换，会造成复杂度提高，可以的话尽量直接去设初值去处理
	bool isValid(vector<string>& cur, int& n, int row, int col)
	{
		for (int i = 0; i < row; ++i)
		{
			if (cur[i][col] == 'Q')
				return false;
		}
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
		{
			if (cur[i][j] == 'Q')
				return false;
		}
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
		{
			if (cur[i][j] == 'Q')
				return false;
		}
		return true;
	}

	void dfs(vector<vector<string>> &res, vector<string>& cur, int& n, int row)
	{
		if (row == n)
		{
			res.push_back(cur);
			return;
		}
		for (int i = 0; i < n; ++i)
		{
			if (isValid(cur, n, row, i))
			{
				cur[row][i] = 'Q';
				dfs(res, cur, n, row + 1);
				cur[row][i] = '.';
			}
		}
	}


	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string>> res;
		if (n == 0)
			return res;
		vector<string> cur(n, string(n, '.'));
		dfs(res, cur, n, 0);
		return res;
	}
};