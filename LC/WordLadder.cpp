/*�����������ʣ���ʼ���ʺ�Ŀ�굥�ʣ���һ�������ֵ䣬���ҳ����еĴӳ�ʼ���ʵ�Ŀ�굥�ʵ����ת�����еĳ��ȣ� 
ÿһ��ת��ֻ�ܸı�һ������ 
ÿһ���м�ʶ�������ڵ����ֵ䵱�� 
���磺 
�����ĳ�ʼ����start="hit"�� 
Ŀ�굥��end ="cog"�� 
�����ֵ�dict =["hot","dot","dog","lot","log"] 
һ����̵�ת������Ϊ"hit" -> "hot" -> "dot" -> "dog" -> "cog", 
���س���5*/
#include<unordered_set>
#include<algorithm>
#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:
	//bfs�������
	//���ö���ÿ�ν���ǰ��Ѱ�ҵ�string��������У��ҵ�һ��ת��string��������У�
	//�����ֵ��еĸ���ɾ��
	int res = 1;
	queue<string> strQueue;
	bool isTransWord(string s, string d)
	{
		if (s.size() != d.size())
			return false;
		int count = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != d[i])
				count++;
		}
		return count == 1 ? true : false;
	}

	int ladderLength(string start, string end, unordered_set<string> &dict) {
		
		strQueue.push(start);
		while (!strQueue.empty())
		{
			int queuesize = strQueue.size();
			while (queuesize > 0)
			{
				string str = strQueue.front();
				strQueue.pop();
				queuesize--;
				if (isTransWord(str, end))
				{
					return res;
				}
				
				for (auto it = dict.begin(); it != dict.end(); it++)
				{
					if (isTransWord(*it, str))
					{
						strQueue.push(*it);
						dict.erase(*it);
						it = dict.begin();    //ɾ��Ԫ�غ���Ҫ���·��������
					}
				}
				
			}
			
			res++;
		}
		return 0;
	}
};

int main()
{
	string start = "hit";
	string end = "cog";
	unordered_set<string> dict = { "hot","dot","dog","lot","log" };
	
	int output;
	Solution sol;
	output = sol.ladderLength(start, end, dict);

	cout << output << endl;
	system("pause");
	return 0;
}