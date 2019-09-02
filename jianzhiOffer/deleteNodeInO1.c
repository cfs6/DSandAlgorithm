// Delete a listnode in O(1)
struct ListNode{
	int value;
	ListNode* next;
};

void deleteListnode(ListNode** pHead, ListNode* pNode){
	if(pHead == nullptr||pNode == nullptr)
		return;
	if(pNode == pHead){
		delete pNode;
		pNode = nullptr;
		*pHead = nullptr;
	}
	else if(pNode->next != nullptr){
		ListNode* pNext = pNode -> next;
		pNode->value = pNext->value;
		pNode->next = pNext->next;
		delete pNext;
		pNext = nullptr;
	}
	else{
		ListNode* newNode = new ListNode();
		while(newNode->next != pNode)
			newNode = newNode->next;
		newNode->next = nullptr;
		delete pNode;
		pNode = nullptr;
	}
}


