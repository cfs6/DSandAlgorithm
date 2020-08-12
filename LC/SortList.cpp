//sort list
//在O(nlogn)的时间内使用常数级空间复杂度对链表进行排序。
struct ListNode {
	int val;
	struct ListNode *next;
 };


class Solution {
public:
	/**
	*
	* @param head ListNode类
	* @return ListNode类
	*/
	//基于单链表的快排
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

	ListNode* sortList(ListNode* head) {                   //为了不改变题目的接口,
		sortRecursive(head, nullptr);                      //重写了方便递归的
		return head;                                       //排序接口
	}
};