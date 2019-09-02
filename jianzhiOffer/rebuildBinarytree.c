//rebuild binarytree
struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
}
template<typename T>
BinaryTreeNode* constructTree(int* preOrder, int* inOrder){
	if(preOrder==nullptr||inOrder==nullptr)
		return 0;
	if(lChilds_in.size()<=1&&rChilds_in.size()<=1){
		return 
	}
	int root = preOrder[0];
	int lChild = preOrder[1];
	int* lChilds_in;
	int* rCHilds_in;
	int* lChilds_pre;
	int* rCHilds_pre;
	int root_order;
	for(int i = 0; i < inOrder.size(); i++){
		while(inOrder[i]!=preOrder[0])
			i++;
	}
	root_order = i;
	BinaryTreeNode* newNode = new BinaryTreeNode();
	for(int m = 0;m < i; m++)
		lChilds_in[m] = inOrder[m];
	for(int n = i+1; n < inOrder.size(); n++)
		rChilds_in[n] = inOrder[n];
	for(int p = 1; p < i+1; p++)
		lChilds_pre[p] = preOrder[p];
	for(int q = i+1; q < preOrder.size(); q++)
		lChilds_pre[q] = preOrder[q];
	newNode->m_nValue = root;
	newNode->m_pLeft = nullptr;
	newNode->m_pRight = nullptr;
	if(lChilds_pre.size() > 0){
		newNode->m_pLeft = constructTree(lChilds_pre, lChilds_in);
	}
	if(rChilds_pre.size()>0){
		newNode->m_pRight = constructTree(rChilds_pre, rChilds_in);
	}
	return root;
}
