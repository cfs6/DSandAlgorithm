/*��������������ÿ�������ڵĽڵ㽻��һ�Σ����������ͷָ��
����,
����1->2->3->4����Ӧ�÷�������2->1->4->3��
��������㷨ֻ��ʹ�ó������Ŀռ䡣�㲻���޸��б��е�ֵ��ֻ���޸Ľڵ㱾��*/
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