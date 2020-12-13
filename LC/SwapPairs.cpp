/*将给定的链表中每两个相邻的节点交换一次，返回链表的头指针
例如,
给出1->2->3->4，你应该返回链表2->1->4->3。
你给出的算法只能使用常量级的空间。你不能修改列表中的值，只能修改节点本身。*/
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
	* @return ListNode类
	*/
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		ListNode* pHead = new ListNode(0);
		pHead->next = head;
		ListNode* pNode = head;
		int count = 0;
		while (pNode != nullptr)
		{
			pNode = pNode->next;
			count++;
		}
		pNode = head;
		ListNode* pre = pHead;
		for (int i = 0; i < (count / 2); ++i)
		{
			for (int j = 1; j < 2; ++j)
			{
				ListNode* next = pNode->next;
				pNode->next = next->next;
				next->next = pNode;
				pre->next = next;
				
			}
			pre = pNode;
			pNode = pNode->next;
		}
		return pHead->next;
	}
};