//Merge two sorted list
ListNode* MergeTwoList(ListNode* pHead1, ListNode* pHead2){
	if(pHead1==nullptr || pHead2==nullptr)
		return nullptr;
	ListNode* pNewHead = nullptr;
	while(pHead1!=nullptr&&pHead2!=nullptr){
		ListNode* pNode =new ListNode;
		if(pHead1->value <= pHead2->value){
			pNode->value = pHead1->value;
			pNode->next = nullptr;
			pHead1 = pHead1->next;
		}
		else{
			pNode->value = pHead2->value;
			pNode->next = nullptr;
			pHead2 = pHead2->next;
		}
		AddNode(pNewHead, pNode);
	}
	if(pHead1!=nullptr){
		while(pHead1!=nullptr){
			AddNode(pNewHead, pHead1);
			pHead1 = pHead1->next;
		}
	}
	if(pHead2!=nullptr){
		while(pHead2!=nullptr){
			AddNode(pNewHead, pHead2);
			pHead2 = pHead2->next;
		}
	}
	return pNewHead;
}

void AddNode(ListNode* pHead, ListNode* pNode){
	if(pHead==nullptr&&pNode==nulllptr)
		return;
	if(pHead==nullptr&&pNode!=nullptr)
		pHead = pNode;
	while(pHead->next!=nullptr){
		pHead = pHead->next;
	}
	pHead->next = pNode;
}
