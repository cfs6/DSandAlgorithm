//Reorder list
/*
�������ĵ�����L�� L 0��L 1������L n-1��L n, 
��������Ϊ�� L 0��L n ��L 1��L n-1��L 2��L n-2���� 
Ҫ��ʹ��ԭ���㷨�����Ҳ��ı�ڵ��ֵ 
���磺 
���ڸ����ĵ�����{1,2,3,4}��������������Ϊ{1,4,2,3}.
*/
/**
* Definition for singly-linked list.*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	//�ҵ������е��Ͽ�Ϊ�ɡ�������������ת����������������������
	void reorderList(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
			return;
		//�ҵ������е�
		ListNode* pNode1 = head;
		ListNode* pNode2 = head;
		while (pNode2->next!=nullptr && pNode2->next->next!=nullptr)
		{
			pNode1 = pNode1->next;
			pNode2 = pNode2->next->next;
		}
		//�Ͽ�����
		//pNewNode1:������ͷ
		ListNode* pNewNode1 = pNode1->next;
		pNode1->next = nullptr;

		//��ת������
		//pre:��ת�������ͷ
		ListNode* pre = nullptr;
		while (pNewNode1!=nullptr)
		{
			ListNode* qNode = pNewNode1->next;       
			pNewNode1->next = pre;
			pre = pNewNode1;
			pNewNode1 = qNode;
		}

		//����������������������
		//resHead:���ս����������ͷ
		ListNode* resHead = head;      
		pNewNode1 = pre;                 //��ת��pNewNode1�Ѿ�Ϊnullptr��
		                                 //��Ҫ���¸�Ϊ������ı�ͷ

		while (resHead != nullptr && pNewNode1 != nullptr)
		{
			ListNode* temp1 = resHead->next;
			ListNode* temp2 = pNewNode1->next;
			pNewNode1->next = resHead->next;
			resHead->next = pNewNode1;
			resHead = temp1;
			pNewNode1 = temp2;
		}	
	}
};


