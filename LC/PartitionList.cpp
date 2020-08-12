/*����һ�������һ��ֵx����xΪ���ս������ֳ������֣�
ʹ����С��x�Ľڵ㶼λ�ڴ��ڻ����x�Ľڵ�֮ǰ��*/
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