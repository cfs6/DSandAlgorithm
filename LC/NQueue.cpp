/*����һ������n������n�ʺ���������аڷŷ��� */
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	//������Ҫ���ȿ�����̫��ת��������ɸ��Ӷ���ߣ����ԵĻ�����ֱ��ȥ���ֵȥ����
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