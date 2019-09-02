//Find the kth to tail in the list
//consider the robustness of the answer
ListNode* FindKthToTail(ListNode* pHead, unsigned int k){
	if(pHead == nullptr||k<=0)
		return nullptr;
	ListNode* pNode = pHead;
	int n = k - 1;
	
	for(int i = 0; i < n; ++i){
		if(pNode->next!=nullptr)
			pNode = pNode->next;
		else
			return nullptr;
	}
	ListNode* pNode2 = pHead;
	while(pNode->next!=nullptr){
		pNode = pNode->next;
		pNode2 = pNode->next;
	}
	return pNode2;
}
