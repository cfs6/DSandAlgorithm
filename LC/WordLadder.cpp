/*给定两个单词（初始单词和目标单词）和一个单词字典，请找出所有的从初始单词到目标单词的最短转换序列的长度： 
每一次转换只能改变一个单词 
每一个中间词都必须存在单词字典当中 
例如： 
给定的初始单词start="hit"， 
目标单词end ="cog"。 
单词字典dict =["hot","dot","dog","lot","log"] 
一个最短的转换序列为"hit" -> "hot" -> "dot" -> "dog" -> "cog", 
返回长度5*/
#include<unordered_set>
#include<algorithm>
#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:
	//bfs层序遍历
	//利用队列每次将当前待寻找的string放入队列中，找到一个转换string即放入队列，
	//并将字典中的该项删除
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
						it = dict.begin();    //删除元素后需要重新分配迭代器
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