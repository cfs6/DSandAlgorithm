/*����n�����֣�����ֱ��ͼ�����ߣ�
ֱ��ͼÿһ���Ŀ��Ϊ1�������ֱ��ͼ�������ε���� */
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	/**
	*
	* @param height int����vector
	* @return int����
	*/
	int largestRectangleArea(vector<int>& height) {
		int m = height.size();
		int Area = 0;
		stack<int> heightStack;
		for (int i = 0; i < m; ++i)
		{
			if (heightStack.empty() || height[i] >= heightStack.top())
			{
				heightStack.push(height[i]);
			}
			else
			{
				int backtraceCount = 0;
				while (!heightStack.empty() && height[i] < heightStack.top())
				{
					backtraceCount++;
					Area = max(Area, backtraceCount * heightStack.top());
					heightStack.pop();
				}
				while (backtraceCount--)
				{
					heightStack.push(height[i]);
				}
				heightStack.push(height[i]);
			}
		}
		int count = 1;
		while (!heightStack.empty())
		{
			Area = max(Area, count*heightStack.top());
			heightStack.pop();
			count++;
		}
		return Area;
	}
};