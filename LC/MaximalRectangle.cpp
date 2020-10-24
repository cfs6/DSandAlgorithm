#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		if (matrix.size() == 0)
			return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int> pointPerCol(n);
		int maxS = 0;
		stack<int> st;
		st.push(-1);
		int num;
		for (int i = 0; i < m; ++i)
		{
			//��ǰ��i����������1�ĸ���������������Ϊ0��������һ��ͳ��
			//j��ʾ�кţ���ֱ��ͼ���������
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == '1')
				{
					pointPerCol[j]++;
				}
				else
				{
					pointPerCol[j] = 0;
				}
			}
			for (int j = 0; j < n; ++j)
			{
				//������Ҫ˼·�������������о���ջ��
				//�����½����оͼ��㵱ǰǰһ��ֱ��ͼ(����ǰջ�����)
				//���������γ�ջ���������Ҵ���jָ��ֱ��ͼ�ĸ߶ȣ�ֱ��ͼ�ľ��룬
				//Ȼ����Գ�ջֱ��ͼ�ĸ߶ȣ�
				//��Ϊ��ǰ�����(��һ�����),ʣ�µ�������Ȼ������ģ�������ȥ
				while (st.top() != -1 && pointPerCol[j]<pointPerCol[st.top()])
				{
					num = st.top();
					st.pop();
					maxS = max(maxS, (j - 1 - st.top())*pointPerCol[num]);
				}
				st.push(j);
			}
			//����ջ�����һ���������е����������ͬ�ϣ�
			while (st.top() != -1)
			{
				num = st.top();
				st.pop();
				maxS = max(maxS, (n - 1 - st.top())*pointPerCol[num]);
			}
		}
		return maxS;
	}
};