/*���������������ϲ�Ϊһ��������
Ҫ���µ�������ͨ��ƴ����������Ľڵ������ɵġ�*/
#include<iostream>
#include<string>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;

	ListNode(int val_) :val(val_), next(nullptr) {}
};


class Solution {
public:
	/**
	*
	* @param l1 ListNode��
	* @param l2 ListNode��
	* @return ListNode��
	*/
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		ListNode* pHead = new ListNode(-1);
		ListNode* pNode = new ListNode(0);
		pNode->val = l1->val <= l2->val ? l1->val : l2->val;
		if (pNode->val == l1->val)
		{
			l1 = l1->next;
		}
		else if (pNode->val == l2->val)
		{
			l2 = l2->next;
		}
		pHead->next = pNode;
		while (l1 || l2)
		{
			ListNode* newNode = new ListNode(0);
			if (l1 != nullptr && l2 != nullptr)
			{
				if (l1->val <= l2->val)
				{
					newNode->val = l1->val;
					l1 = l1->next;
				}
				else
				{
					newNode->val = l2->val;
					l2 = l2->next;
				}
			}
			else if (l1 && l2 == nullptr)
			{
				newNode->val = l1->val;
				l1 = l1->next;
			}
			else if (l1 == nullptr && l2)
			{
				newNode->val = l2->val;
				l2 = l2->next;
			}
			pNode->next = newNode;
			pNode = pNode->next;
		}
		return pHead->next;
	}
};