//Find first commen node

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct ListNode {
	int m_nKey;
	ListNode* m_pNext;
};

ListNode* FindFirstCommenNode(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == nullptr || pHead2 == nullptr)
		return nullptr;
	stack<ListNode*> pStack1;
	stack<ListNode*> pStack2;
	while (pHead1 != nullptr) {
		pStack1.push(pHead1);
		pHead1 = pHead1->m_pNext;
	}
	while (pHead2 != nullptr) {
		pStack2.push(pHead2);
		pHead2 = pHead2->m_pNext;
	}
	ListNode* pCommen;
	while ((!pStack1.empty()) && (!pStack2.empty())) {
		if (pStack1.top()->m_nKey == pStack2.top()->m_nKey) {
			pCommen = pStack1.top();
			pStack1.pop();
			pStack2.pop();
		}
		else {
			break;
		}
	}
	return pCommen;
}

