/*
�������������еĽڵ�ÿ\ k k ��һ�鷭ת�����ط�ת�������
��������еĽڵ�������\ k k �ı����������ʣ�µĽڵ㱣��ԭ��
�㲻�ܸ��Ľڵ��е�ֵ��ֻ�ܸ��Ľڵ㱾��
Ҫ��ռ临�Ӷ� \ O(1) O(1)
���磺
������������1\to2\to3\to4\to51��2��3��4��5
���� \ k = 2 k=2, ��Ӧ�÷��� 2\to 1\to 4\to 3\to 52��1��4��3��5
���� \ k = 3 k=3, ��Ӧ�÷��� 3\to2 \to1 \to 4\to 53��2��1��4��5
*/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int val) :val(val) {}
};


class Solution {
public:

	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr || head->next == nullptr || k < 2)
			return head;
		ListNode* pHead = new ListNode(0);
		pHead->next = head;
		ListNode* pNode = head;
		int count = 0;                                //����������
		while (head != nullptr)
		{
			count++;
			head = head->next;
		}
		ListNode* pre = pHead;
		ListNode* temp = nullptr;
		for (int i = 0; i < (count / k); ++i)         
		{
			for (int j = 1; j < k; ++j)
			{
				temp = pNode->next;
				pNode->next = temp->next;
				temp->next = pre->next;
				pre->next = temp;
			}
			pre = pNode;
			pNode = pNode->next;
		}
		return pHead->next;
	}
};