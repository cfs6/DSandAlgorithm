/*给出一个链表和一个值x，以x为参照将链表划分成两部分，
使所有小于x的节点都位于大于或等于x的节点之前。*/
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
	ListNode* partition(ListNode* head, int x) {
		if (head == nullptr)
			return;
		ListNode* pHead1 = new ListNode(-1);
		ListNode* pHead2 = new ListNode(-2);
		ListNode* cur1 = pHead1;
		ListNode* cur2 = pHead2;
		while (head != nullptr)
		{
			if (head->val < x)
			{
				
				cur1->next = head;
				cur1 = cur1->next;
			}
			else
			{
				cur2->next = head;
				cur2 = cur2->next;
			}
			head = head->next;
		}
		cur1->next = pHead2->next;
		cur2->next = nullptr;
		return pHead1->next;
	}
};