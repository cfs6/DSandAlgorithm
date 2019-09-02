//Reverse List
ListNode* ReverseList(ListNode* pHead){
	if(pHead == nullptr)
		return nullptr;
	ListNode* pNode = pHead;
	ListNode* qNode = pNode->next;
	if(qNode==nullptr)
		return pNode;
	ListNode* nNode = nullptr;
	pNode->next =nullptr;
	while(qNode!=nullptr){
		nNode = qNode->next;
		if(nNode==nullptr)
			return qNode;
		qNode->next = pNode;
		pNode = qNode;
		qNode = nNode;
	}
	return qNode;
}
