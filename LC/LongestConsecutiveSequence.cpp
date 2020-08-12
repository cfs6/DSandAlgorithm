/*����һ������������������飬���������Ԫ�����еĳ��ȡ� 
���磺 
����������Ϊ[100, 4, 200, 1, 3, 2], 
�������Ԫ������Ϊ[1, 2, 3, 4]. ����������еĳ��ȣ�4
����Ҫ����ʱ�临�Ӷ���O��n��֮�ڵ��㷨*/
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
	/**
	*
	* @param num int����vector
	* @return int����
	*/
	//�ռ任ʱ��
	//unordered_set����ɢ�б�Ĳ���ʱ��Ϊo(1)
	//����num�е�ֵ��ͬʱ�����ǰ���������㣬�ҵ���ɾ��������������������
	//��ǰ�˵ĲΪ��������
	int longestConsecutive(vector<int>& num) {
		int res = 0;
		unordered_set<int> numset(num.begin(),num.end());
		for (auto pernum:num)
		{
			if (find(numset.begin(), numset.end(), pernum) == numset.end())
			{
				continue;
			}
			int low = pernum;
			int high = pernum;
			numset.erase(pernum);
			while (find(numset.begin(), numset.end(), high + 1) != numset.end())
			{
				numset.erase(++high);
			}
			while (find(numset.begin(), numset.end(), low - 1) != numset.end())
			{
				numset.erase(--low);
			}
			res = max(res, high - low + 1);
		}
		return res;
	}
};