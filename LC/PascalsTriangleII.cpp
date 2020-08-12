/*给出一个索引k，返回杨辉三角的第k行 
例如，k=3， 
返回[1,3,3,1].*/

#include<vector>
using namespace std;
class Solution {
public:
	vector<int> res;
	vector<vector<int>> triangle;
	vector<int> getRow(int rowIndex) {
		vector<int> c1;
		c1.push_back(1);
		if (rowIndex == 0)
			return c1;
		triangle.push_back(c1);
		for (int i = 1; i < rowIndex+1; ++i)
		{
			vector<int> temp(i + 1, 1);
			for (int j = 1; j < i; ++j)
			{
				temp[j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
			}
			triangle.push_back(temp);
		}

		return triangle[triangle.size() - 1];
	}
};