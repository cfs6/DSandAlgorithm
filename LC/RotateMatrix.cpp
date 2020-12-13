/*��תͼ��
����һ���ö�ά�����ʾ��ͼ��
���ظ�ͼ��˳ʱ����ת90�ȵĽ��

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