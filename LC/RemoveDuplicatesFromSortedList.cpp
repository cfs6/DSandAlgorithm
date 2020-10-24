/*删除给出链表中的重复元素（链表中元素从小到大有序），
使链表中的所有元素都只出现一次
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
	* @param head ListNode类
	* @param x int整型
	* @return ListNode类
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