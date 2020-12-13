/*实现函数 strStr。
函数声明如下：
char *strStr(char *str, char *dest)
返回一个指针，指向dest第一次在str中出现的位置，如果dest不是str的子串，则返回null*/
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	char *strStr(char *str, char *dest) {
		if (str == NULL && dest == NULL)
			return NULL;
		if (str == NULL || dest == NULL)
			return NULL;
		size_t result = strStrImpl(str, dest);
		if (result == -1)
			return NULL;
		char* resPtr = str;
		size_t index = 0;
		while (index < result)
		{
			index++;
			resPtr++;
		}
		return resPtr;
	}
	char strStrImpl(string str, string dest)
	{
		size_t res = str.find(dest);
		return (res != str.npos) ? res : -1;
	}
};