/*����һ��ֻ������Сд��ĸ�Ϳո���ַ���s���뷵���ַ��������һ�����ʵĳ���
����ַ�����û�����һ�����ʣ��򷵻�0
ע�⣺���ʵĶ����ǽ��ɷǿո��ַ���ɵ��ַ����С�
���磺
s ="Hello World",
����5�� */
/*
ע�������������" "�� " a"�� " a "��
*/
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		if (s == nullptr)
			return 0;
		int lastSpace = 0;
		string str = s;
		lastSpace = str.rfind(' ');
		while (lastSpace == (str.length() - 1))
		{
			str = str.substr(0, str.size() - 1);
			if (str.length() == 0)
				return 0;
			lastSpace = str.rfind(' ');
			if (lastSpace == 0)
				break;
		}
		if (str.length() == 1 && lastSpace == 0)
			return 0;
		else
			return str.length() - 1 - lastSpace;
	}
};