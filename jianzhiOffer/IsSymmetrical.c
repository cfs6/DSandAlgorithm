//Is the tree symmetrical
#include<vector>
struct BinaryTreeNode{
	double m_value;
	BinaryTreeNode* m_left;
	BinaryTreeNode* m_right;
}
bool isSymmetrical(BinaryTreeNode* root){
	if(root==nullptr)
		return false;
	vector<int> preOrder;
	vector<int> symOrder;
	preOrder = preOrder(root, preOrder);
	symOrder = symPreOrder(root, symOrder);
	for(int i = 0; i < preOrder.size(); ++i){
		if(preOrder[i] != symOrder[i])
			return false;
	}
	return true;
}

vector<int> symPreOrder(BinaryTreeNode* root, vector<int> Order_){
	Order_.push_back(root->value);
	if(root->m_right!=nullptr){
		symPreOrder(root->m_right, Order_);
	}
	if(root->m_left!=nullptr){
		symPreOrder(root->m_left, Order_);
	}
	return Order_;
}
vector<int> preOrder(BinaryTreeNode* root, vector<int> Order_){
	Order_.push_back(root->value);
	if(root->m_left!=nullptr){
		preOrder(root->m_left, Order_);
	}
	if(root->m_right!=nullptr){
		preOrder(root->m_right, Order_);
	}
	return Order_;
}

//Another way
//
bool isSymmetrical(BinaryTreeNode* root){
	return isSymmetrical(root, root);
}

bool isSymmetrcial(BinaryTreeNode* root1, BinaryTreeNode* root2){
	if(root1==nullptr&&root2==nullptr)
		return true;
	if(root1==nullptr||root2==nullptr)
		return false;
	if(root1->m_value!=root2->m_value)
		return false;
	return isSymmetrical(root1->m_left, root2->m_right)&&isSymmetrical(root1->m_right, root2->m_left);
}
