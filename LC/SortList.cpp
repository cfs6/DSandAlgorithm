//sort list
//��O(nlogn)��ʱ����ʹ�ó������ռ临�Ӷȶ������������
struct ListNode {
	int val;
	struct ListNode *next;
 };


class Solution {
public:
	/**
	*
	* @param head ListNode��
	* @return ListNode��
	*/
	//���ڵ�����Ŀ���
	void swap(int& pvalue, int& qvalue)
	{
		int temp = pvalue;
		pvalue = qvalue;
		qvalue = temp;
	}

	ListNode* getPartition(ListNode* pBegin, ListNode* pEnd) 
	{
		ListNode* pNode = pBegin;
		ListNode* qNode = pNode->next;
		int key = pBegin->val;
		while (qNode != pEnd)
		{
			if (qNode->val < key)
			{
				pNode = pNode->next;
				swap(pNode->val, qNode->val);
			}
			qNode = qNode->next;
		}
		swap(pBegin->val, pNode->val);
		return pNode;
	}

	void sortRecursive(ListNode* pbegin, ListNode* pend)
	{
		if (pbegin != pend)
		{
			ListNode* pivot = getPartition(pbegin, pend);
			sortRecursive(pbegin, pivot);
			sortRecursive(pivot->next, pend);
		}
	}

	ListNode* sortList(ListNode* head) {                   //Ϊ�˲��ı���Ŀ�Ľӿ�,
		sortRecursive(head, nullptr);                      //��д�˷���ݹ��
		return head;                                       //����ӿ�
	}
};