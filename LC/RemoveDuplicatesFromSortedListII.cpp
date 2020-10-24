/*����һ���������������
ɾ�������е������ظ����ֵ�Ԫ�أ�ֻ����ԭ������ֻ����һ�ε�Ԫ�ء�*/
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int val_) :val(val_) {}
};


class Solution {
public:
	/**
	*
	* @param head ListNode��
	* @return ListNode��
	*/
	

	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		vector<int> nodes;
		while (head)
		{
			nodes.push_back(head->val);
			head = head->next;
		}
		bool isDuplicate = false;
		vector<int>::iterator it = nodes.begin();
		while (it != nodes.end())
		{
			if ((it + 1) != nodes.end() && *it == *(it + 1))
			{
				it = nodes.erase(it);
				isDuplicate = true;
				continue;
			}
			if (isDuplicate)
			{
				it = nodes.erase(it);
				isDuplicate = false;
				continue;
			}
			it++;
		}
		if (nodes.size() == 0)
			return nullptr;
		ListNode* newHead = new ListNode(-1);
		ListNode* pNode = new ListNode(nodes[0]);
		newHead->next = pNode;
		for (int i = 1; i < nodes.size(); ++i)
		{
			ListNode* newNode = new ListNode(nodes[i]);
			newNode->next = nullptr;
			pNode->next = newNode;
			pNode = pNode->next;
		}
		return newHead->next;
	}
};