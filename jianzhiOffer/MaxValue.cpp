//jianzhi47.MaxValueOfGifts
//by DP
#include<iostream>
#include<vector>
using namespace std;

int MaxValue(vector<vector<int>> num) {
	int rows = num.size();
	int cols = num[0].size();
	vector<vector<int>> res(rows,vector<int>(cols));
	res[0][0] = num[0][0];
	for (int j = 1; j < cols; ++j) {
		res[0][j] = res[0][j - 1]+num[0][j];
	}
	for (int i = 1; i < rows; ++i) {
		res[i][0] = res[i][0] + num[i][0];
	}
	for (int i = 1; i < rows; ++i) {
		for (int j = 1; j < cols; ++j) {
			res[i][j] = res[i - 1][j] > res[i][j - 1] ? (res[i - 1][j] + num[i][j]) : (res[i][j - 1] + num[i][j]);
		}
	}
	return res[rows - 1][cols - 1];
}

