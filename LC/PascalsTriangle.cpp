/*给出一个值numRows，生成杨辉三角的前numRows行 
例如，给出 numRows = 5, 
返回 
[↵     [1],↵    [1,1],↵   [1,2,1],↵  [1,3,3,1],↵ [1,4,6,4,1]↵]*/
#include<vector>
using namespace std;

class Solution {
public:
	//除边界外各点的值为上一行可连接两点之和
	//注意边界
	vector<vector<int>> res;

	vector<vector<int> > generate(int numRows) {
		if (numRows == 0)
			return res;
		vector<int> c1;
		c1.push_back(1);

		res.push_back(c1);
		if (numRows == 1)
		{
			return res;
		}
		for(int i=1; i<numRows; ++i)
		{
			vector<int> tempVec;
			tempVec.push_back(1);
			for (int j = 1; j<i; ++j)
			{
				int cur = res[i - 1][j - 1] + res[i - 1][j];
				tempVec.push_back(cur);
			}
			tempVec.push_back(1);
			res.push_back(tempVec);
		}
		return res;
	}
};

