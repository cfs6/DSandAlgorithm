/*����һ���������ַ�'('��')'���ַ�����������ĸ�ʽ��ȷ�������Ӵ��ĳ��ȡ�
�����ַ���"(()"��˵����ĸ�ʽ��ȷ���Ӵ���"()"������Ϊ2.
�پ�һ�����ӣ������ַ���")()())",��˵����ĸ�ʽ��ȷ���Ӵ���"()()"������Ϊ4.*/
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	/**
	*
	* indexStack�б�����������index, last ���������һ�ο�ʼͳ�Ƶ�Index, ����"("ѹջ������")"��ջ�գ�
	* ���")"û���ô�������last, ��ջ�ǿգ����ջ��֮����ݳ�ջ��ջ�Ƿ�Ϊ�ո���maxLen 
	* 
	*/
	int longestValidParentheses(string s) {
		stack<int> indexStack;
		int last = 0;
		int maxLen = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == '(')
			{
				indexStack.push(i);
			}
			else
			{
				if (indexStack.empty())
				{
					last = i + 1;
				}
				else
				{
					indexStack.pop();
					if (indexStack.empty())
					{
						maxLen = max(maxLen, i - last + 1);    //ע�ⳤ�ȼ�����Ҫ+1
					}
					else
					{
						maxLen = max(maxLen, i - indexStack.top());
					}
				}
			}
		}
		return maxLen;
	}
};