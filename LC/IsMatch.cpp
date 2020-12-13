//通配符匹配
/*
请实现支持'?'and'*'.的通配符模式匹配
'?' 可以匹配任何单个字符。
'*' 可以匹配任何字符序列（包括空序列）。
返回两个字符串是否匹配
*/
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
class Solution {
public:
	/*关键是 '*' ，这里定义了 i 和 j 的回溯点:每当遇到 '*' 时，
	记录 i 的回溯点 i_recall = i;记录 j 的回溯点 j_recall = ++j，
	这里选择 j 自增后的位置，因为此时 j 为 '*'，尝试用后面的模式
	来匹配该元素。 
	当遇到不能匹配的点时，就会进入到第 3 个 if，
	此时把 i 回溯到 i_recall 后，同时 i_recall 自增，j 回溯到 j_recall，
	表示将原来记录的回溯点用 '*' 来匹配，再重新做这一轮的匹配。 
	最后要把末尾的 '*' 都忽略，若 p[j] 为空则代表匹配完成，
	若还有剩余元素说明不匹配。*/
	bool isMatch(string s, string p)
	{
		int i = 0, j = 0;
		int j_recall = 0, i_recall = 0;
		while (s[i])
		{
			if (p[j] == '?' || s[i]==p[j])
			{
				++i;
				++j;
				continue;
			}
			if (p[j] == '*')
			{
				i_recall = i;
				j_recall = ++j;
				continue;
			}
			if (j_recall)
			{
				i = ++i_recall;
				j = j_recall;
				continue;
			}
			return false;	
		}
		while (p[j] == '*')
			++j;
		return !p[j];
	}
};