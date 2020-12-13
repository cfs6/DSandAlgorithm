//���ظ������ֵ���������
/*
����һ����ܰ����ظ�������֣����ظ������ֵ���������
���磻
[1,1,2]���������£�
[1,1,2],[1,2,1], [2,1,1].
*/
#include<vector>
#include<set>
#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
	/*
	1. ����ظ���������  �ȶ�����num�������򣬱�֤�ظ��������ڣ�
	�����ں��������У���������������һ����ǰһ����ȣ��򲻴���
	2����������Ƿ��������list��������  ʹ�ö���bool��������used��
	���ֵ�ǰֵ�Ƿ��ѽ������е���
	3�������������  ��1����list���ȵ���num����ѹ������res
	��2��������num����forѭ��  �߽�������  ����ǰֵ��ʹ�ù���������
	����ǰֵ��ǰһֵ��ȣ���ǰһֵδʹ�ù���������
	��������112��ѭ����һ��1����һλʱ���ڶ�λ�ǵڶ���1���ᱻ��¼��
	����ѭ���ڶ���1����һλʱ���ڶ�λ�ǵ�һ��1���Ͳ��ᱻ��¼�������ظ���
	��ǰֵѹ�벢������Ϊ����list��Ԫ�أ���used������Ӧλ��true
	����ǰlist��num��used��res�������к��������еݹ�
	��used�ж�Ӧλ��false��list������ǰֵ������forѭ�� */
	vector<vector<int>> result;
	void dfs(vector<int>& num, vector<int>& res, deque<bool>& used)
	{
		if (res.size() == num.size())
		{
			result.push_back(res);
			return;
		}
		for (int i = 0; i < num.size(); ++i)
		{
			if (used[i])
				continue;
			if (i > 0 && num[i] == num[i - 1] && !used[i - 1])
				continue;
			res.push_back(num[i]);
			used[i] = true;
			dfs(num, res, used);
			used[i] = false;
			res.pop_back();
		}
	}

	vector<vector<int> > permuteUnique(vector<int> &num) {
		if (num.size() == 0)
			return result;
		sort(num.begin(), num.end());
		deque<bool> used;
		for (int i = 0; i < num.size(); ++i)
			used.push_back(false);
		vector<int> res;
		dfs(num, res, used);

		return result;
	}
};






// ����ȡ������swap���ȥ�صķ������ᱬջ
class Solution {
public:
	vector<vector<int>> result;
//	vector<int> res;
	void dfs(vector<int>& num, int start)
	{
		if (start == num.size() - 1)
			return;
		for (int i = start; i < num.size()-1; ++i)
		{
			for (int j = i+1; j < num.size(); ++j)
			{
				result.push_back(num);
				swap(num[i], num[j]);
				dfs(num,start+1);
				swap(num[i], num[j]);
			}
		}


	}

	vector<vector<int> > permuteUnique(vector<int> &num) {
		
		if (num.size() == 0)
			return result;
		dfs(num, 0);
		return result;
	}
};