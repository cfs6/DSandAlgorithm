//insertion sort list
//基于单链表的插入排序
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
	* @param head ListNode类
	* @return ListNode类
	*/
	//开辟新的链表头结点，以dummy保存，从head链表中取结点插入
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode dummy(0);               //保存链表头
		ListNode* currentNode;           //当前节点，即待插入节点
		ListNode* nextNode;              //当前节点的下一节点
		ListNode* pNode;                
		currentNode = head;
		while (currentNode)
		{
			pNode = &dummy;
			nextNode = currentNode->next;
			//确定待插入节点的插入位置
			while (pNode->next && currentNode->val > pNode->next->val)
			{
				pNode = pNode->next;
			}
			//插入节点
			currentNode->next = pNode->next;
			pNode->next = currentNode;
			
			currentNode = nextNode;
			
		}
		return dummy.next;
	}
};