//Reorder list
/*
将给定的单链表L： L 0→L 1→…→L n-1→L n, 
重新排序为： L 0→L n →L 1→L n-1→L 2→L n-2→… 
要求使用原地算法，并且不改变节点的值 
例如： 
对于给定的单链表{1,2,3,4}，将其重新排序为{1,4,2,3}.
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
	//找到链表中点后断开为旧、新两个链表，翻转新链表后将新链表结点逐个插入
	void reorderList(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
			return;
		//找到链表中点
		ListNode* pNode1 = head;
		ListNode* pNode2 = head;
		while (pNode2->next!=nullptr && pNode2->next->next!=nullptr)
		{
			pNode1 = pNode1->next;
			pNode2 = pNode2->next->next;
		}
		//断开链表
		//pNewNode1:新链表头
		ListNode* pNewNode1 = pNode1->next;
		pNode1->next = nullptr;

		//翻转新链表
		//pre:翻转后的链表头
		ListNode* pre = nullptr;
		while (pNewNode1!=nullptr)
		{
			ListNode* qNode = pNewNode1->next;       
			pNewNode1->next = pre;
			pre = pNewNode1;
			pNewNode1 = qNode;
		}

		//将新链表逐个结点插入旧链表
		//resHead:最终结果所得链表头
		ListNode* resHead = head;      
		pNewNode1 = pre;                 //翻转后pNewNode1已经为nullptr，
		                                 //需要重新赋为新链表的表头

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


