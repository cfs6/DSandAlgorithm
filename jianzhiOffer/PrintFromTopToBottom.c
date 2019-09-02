// Print a tree from top to bottom
#include<queue>
void PrintFromTopToBottom(BinaryTreeNode* pRoot){
	if(pRoot==nullptr)
		return;
	std::queue<BinaryTreeNode*> pQueue;
	pQueue.push(pRoot);
	printBFS(pQueue);
}

void printBFS(queue<BinaryTreeNode*> *pQueue){
	while(!pQueue.empty()){
		BinaryTreeNode* pNode = pQueue.front();
		std::cout<<pNode->m_value<<" ";
		if(pNode->m_left!=nullptr)
			pQueue.push(pNode->m_left);
		if(pNode->m_right!=nullptr)
			pQueue.push(pNode->m_right);
		pQueue.pop();
	}
}
