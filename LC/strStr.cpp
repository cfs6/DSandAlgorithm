/*ʵ�ֺ��� strStr��
�����������£�
char *strStr(char *str, char *dest)
����һ��ָ�룬ָ��dest��һ����str�г��ֵ�λ�ã����dest����str���Ӵ����򷵻�null*/
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