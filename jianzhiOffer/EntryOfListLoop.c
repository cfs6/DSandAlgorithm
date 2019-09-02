//Find the entry node of the loop(meeting node)
//
ListNode* entryOfListLoop(ListNode* pHead){
	if(phead==nullptr)
		return nullptr;
	if(!ListNodeHasLoop(pHead))
		return nullptr;
	ListNode* pNode1 = pHead;
	ListNdoe* pNode2 = pHead;
	while(pNode1->next->next!=nullptr && pNode2!=pNode1){
		pNode1 = pNode1->next->next;
		pNode2 = pNode2->next;
	}
	int loopCount = 1;
	pNode2 = pNode2->next;
	while(pNode2!=pNode1){
		pNode2 = pNode2->next;
		++loopCount;
	}
	pNode1 = pHead;
	pNode2 = pHead;
	while(loopCount!=0){
		pNode1 = pNode1->next;
		--loopCount;
	}
	while(pNode1!=pNode2){
		pNode1 = pNode1->next;
		pNode2 = pNode2->next;
	}
	return pNode2;
}

bool ListNodeHasLoop(ListNode* pHead){
	if(pHead == nullptr)
		return false;
	ListNode* pNodeSlow = pHead;
	ListNode* pNodeFast = pHead;
	while(pNodefast->next->next != nullptr && pNodeFast!=pNodeSlow){
		pNodeFast = pNodeFast->next->next;
		pNodeSlow = pNodeSlow->next;
	}
	if(pNodeFast = pNodeSlow)
		return true;
	else
		return false;
}
