/*旋转图像
给出一个用二维矩阵表示的图像
返回该图像顺时针旋转90度的结果

*/
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		vector<vector<int>> newMatrix(col, vector<int>(row));
		int newRow = 0, newCol = 0;
		for (int i = 0; i<col; ++i)
		{
			newCol = 0;
			for (int j = row - 1; j >= 0; --j)
			{
				newMatrix[newRow][newCol] = matrix[j][i];
				newCol++;
			}
			newRow++;
		}
		matrix.clear();
		matrix = newMatrix;
	}
};