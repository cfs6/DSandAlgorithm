/*将一个链表m位置到n位置之间的区间反转，
要求使用原地算法，并且在一次扫描之内完成反转。*/
struct ListNode {
	int val;
	struct ListNode *next;
};


class Solution {
public:
	/**
	*
	* @param head ListNode类
	* @param m int整型
	* @param n int整型
	* @return ListNode类
	*/


	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == nullptr)
			return nullptr;
		if (head->next == nullptr)
			return head;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pNode = dummy;
		ListNode* rhead = nullptr;
		ListNode* rtail = nullptr;
		ListNode* res = nullptr;
		for (int i = 0; i < m - 1; ++i)
		{
			pNode = pNode->next;
		}
		rhead = pNode->next;
		pNode->next = nullptr;

		ListNode* prev = nullptr;
		ListNode* pcur = rhead;
		ListNode* pnext = rhead->next;
		for (int i = m; i <= n; ++i)
		{
			pcur->next = prev;
			prev = pcur;
			pcur = pnext;
			pnext = pnext->next;
		}
		res = pcur;
		pNode->next = prev;
		rhead->next = res;
		ListNode* phead = dummy->next;
		dummy->next = nullptr;
		delete dummy;
		return phead;

	}
};