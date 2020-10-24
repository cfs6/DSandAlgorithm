/*给出一个二维字符数组和一个单词，判断单词是否在数组中出现，
单词由相邻单元格的字母连接而成，相邻单元指的是上下左右相邻。
同一单元格的字母不能多次使用。*/
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	bool isOut(int r, int c, int rows, int cols)
	{
		return r < 0 || r >= rows || c < 0 || c >= cols;
	}

	bool existChar(vector<vector<char>> &board, string& word, int r, int c, int start)
	{
		if (start >= word.size())
			return true;
		if (isOut(r, c, board.size(), board[0].size()) || word[start] != board[r][c])
			return false;
		int dx[] = { 0,0,1,-1 };
		int dy[] = { 1,-1,0,0 };
		char temp = board[r][c];
		board[r][c] = '.';
		for (int k = 0; k < 4; ++k)
		{
			if (existChar(board, word, r + dx[k], c + dy[k], start + 1))
				return true;
		}
		board[r][c] = temp;
		return false;
	}

	bool exist(vector<vector<char> > &board, string word) {
		for (int r = 0; r < board.size(); ++r)
		{
			for (int c = 0; c < board[0].size(); ++c)
			{
				if (board[r][c] == word[0])
				{
					if (existChar(board, word, r, c, 0))
						return true;
				}
			}
		}
		return false;
	}
};


int main()
{
	vector<char> v1{ 'A','B','C','E' };
	vector<char> v2{ 'S','F','C','S' };
	vector<char> v3{ 'A','D','E','E' };
	vector<vector<char>> v{ v1,v2,v3 };
	/*
	for (int i = 0; i < v.size(); ++i)
	{
	for (int j = 0; j < v[i].size(); ++j)
	{
	cout << v[i][j];
	}
	cout << endl;
	}*/
	string word{ "ABCCED" };
	string word2{ "SEE" };
	string word3{ "ABCB" };
	Solution sol;
	cout << sol.exist(v, word) << endl;
	cout << sol.exist(v, word2) << endl;
	cout << sol.exist(v, word3) << endl;


	system("pause");
}