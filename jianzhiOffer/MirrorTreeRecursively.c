// Mirror the binarytree
struct BinaryTreeNode{
	double m_value;
	BinaryTreeNode* m_left;
	BinaryTreeNode* m_right;
}

void MirrorTree(BinaryTreeNode* root){
	if(root==nullptr)
		return;
	if(root->m_left==nullptr&&root->m_right==nullptr)
		return;
	BinaryTreeNode* newNode = nullptr;
	if(root->m_left!=nullptr&&root->m_right!=nullptr){
		newNode = root->m_left;
		root->left = root->right;
		root->right = newNode;
	}
	if(root->m_left!=nullptr&&root->m_right==nullptr){
		newNode = root->m_left;
		root->right = newNode;
		root->left = nullptr;
	}
	if(root->m_right!=nullptr&&root->m_left==nullptr){
		newNode = root->m_right;
		root->m_left = newNode;
		root->m_right = nullptr;
	}
	if(root->m_left!=nullptr)
		MirrorTree(root->m_left);
	if(root->m_right!=nullptr)
		MirrorTree(root->m_right);
}
