//Linked list cycle
//对于一个给定的链表，返回环的入口节点，如果没有环，返回null 
#define NULL nullptr
//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == nullptr||head->next==nullptr)
			return;
//		bool hasCycle = false;
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* pNode = head;
		//根据快、慢结点是否会汇合判断是否存在环
		do {
			if (fast!=nullptr && fast->next != nullptr && slow != nullptr)
			{
				fast = fast->next->next;
				slow = slow->next;
			}
			else
				break;
		} while (fast != slow);
		//若快、慢结点中有其一为nullptr,则该链表中不存在环
		if (fast == nullptr || fast->next == nullptr || slow == nullptr)
			return nullptr;
		//
		while (slow != pNode)
		{
			slow = slow->next;
			pNode = pNode->next;
		}
		return pNode;
	}
};