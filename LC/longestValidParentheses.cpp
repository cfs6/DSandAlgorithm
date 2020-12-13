/*给出一个仅包含字符'('和')'的字符串，计算最长的格式正确的括号子串的长度。
对于字符串"(()"来说，最长的格式正确的子串是"()"，长度为2.
再举一个例子：对于字符串")()())",来说，最长的格式正确的子串是"()()"，长度为4.*/
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	/**
	*
	* indexStack中保存左括弧的index, last 保存最近上一次开始统计的Index, 遇到"("压栈，遇到")"若栈空，
	* 则该")"没有用处，更新last, 若栈非空，则出栈，之后根据出栈后栈是否为空更新maxLen 
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
						maxLen = max(maxLen, i - last + 1);    //注意长度计算需要+1
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