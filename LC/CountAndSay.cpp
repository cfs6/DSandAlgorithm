/*������е�ǰ�������£�
1, 11, 21, 1211, 111221, ...
1������1��1����11
11������2��1������21
21������1��2��1��1������1211
����һ������n����������еĵ�n��
ÿһ�ζ�������ǰһ��Ϊ����
ע�⣺�����е��������ַ�����ʾ*/
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	/**
	*
	* @param n int����
	* @return string�ַ���
	*/
	//ʹ��count����������ͬ�����ָ����� ע�⵹���ڶ������ֺ����һ������
	string result;
	string res;
	string countAndSay(int n) {
		res = "1";
		if (n == 1)
			return res;
		res = "11";
		if (n == 2)
			return res;
		for (int i = 3; i <= n; ++i)
		{
			int count = 1;
			result.clear();
			for (int k = 0; k < res.size() - 1; ++k)
			{
				if (res[k] == res[k + 1])
				{
					count++;
					if ((k + 1) == (res.size() - 1))
					{
						result += ('0' + count);
						result += res[k];
					}
				}
				else if (res[k] != res[k + 1])
				{
					result += ('0' + count);
					result += res[k];
					if ((k + 1) == (res.size() - 1))
					{
						result += '1';
						result += res[k + 1];
					}
					count = 1;
				}
			}
			res.clear();
			res = result;
		}
		return result;
	}
};


