//insertion sort list
//���ڵ�����Ĳ�������
#include<iostream>
using namespace std;
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
	//�����µ�����ͷ��㣬��dummy���棬��head������ȡ������
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode dummy(0);               //��������ͷ
		ListNode* currentNode;           //��ǰ�ڵ㣬��������ڵ�
		ListNode* nextNode;              //��ǰ�ڵ����һ�ڵ�
		ListNode* pNode;                
		currentNode = head;
		while (currentNode)
		{
			pNode = &dummy;
			nextNode = currentNode->next;
			//ȷ��������ڵ�Ĳ���λ��
			while (pNode->next && currentNode->val > pNode->next->val)
			{
				pNode = pNode->next;
			}
			//����ڵ�
			currentNode->next = pNode->next;
			pNode->next = currentNode;
			
			currentNode = nextNode;
			
		}
		return dummy.next;
	}
};