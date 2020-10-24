/*给定两个单词word1和word2，请计算将word1转换为word2至少需要多少步操作。
你可以对一个单词执行以下3种操作：
a）在单词中插入一个字符
b）删除单词中的一个字符
c）替换单词中的一个字符
*/
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	/**
	*
	* @param word1 string字符串
	* @param word2 string字符串
	* @return int整型
	*/
	// dp[i][j]代表由word1的前i个子串变为word2的前j个子串的花费
	// 其中i，j均可为0，代表空串:""
	// 如果这两个字符相等，那么交由上一种情况处理,如abc，dfc                
	// 这种情况与ab，df花费是一样的                
	// 不然就要在删除，插入，修改中取花费最小的那个
	int minDistance(string word1, string word2) {
		int strLength1 = word1.size();
		int strLength2 = word2.size();

		vector<vector<int> > res(strLength1 + 1, vector<int>(strLength2 + 1));
		for (int i = 0; i <= strLength1; ++i)
		{
			for (int j = 0; j <= strLength2; ++j)
			{
				if (i == 0)
				{
					res[i][j] = j;
				}
				else if (j == 0)
				{
					res[i][j] = i;
				}
				else
				{    //min()只接受两个参数
					res[i][j] = min(res[i - 1][j] + 1, min(res[i][j - 1] + 1,
						res[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1)));
				}
			}
		}
		return res[strLength1][strLength2];
	}
};