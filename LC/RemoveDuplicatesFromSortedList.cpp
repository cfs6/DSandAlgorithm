/*ɾ�����������е��ظ�Ԫ�أ�������Ԫ�ش�С�������򣩣�
ʹ�����е�����Ԫ�ض�ֻ����һ��
*/
#include<iostream>
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
	* @param x int����
	* @return ListNode��
	*/
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		ListNode* newHead = new ListNode(-1);
		newHead->next = head;
		while (head != nullptr && head->next != nullptr)
		{
			while (head->next != nullptr && head->val == head->next->val)
			{
				head->next = head->next->next;
			}
			head = head->next;
		}
		return newHead->next;
	}

};