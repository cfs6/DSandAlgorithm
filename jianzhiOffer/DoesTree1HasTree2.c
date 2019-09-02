//Does tree1 has tree2 as its substructure
struct BinaryTreeNode{
	double m_value;
	BinaryTreeNode* m_left;
	BinaryTreeNode* m_right;
}

bool HasSubtree(BinaryTreeNode* root1, BinaryTreeNode* root2){
	bool result = false;
	if(root1!=nullptr&&root2!=nullptr){
		if(equal(root1->value, root2->value)){
			result = DoesTree1HasTree2(root1, root2);
		}
		if(!result)
			result = HasSubTree(root1->m_left, root2);
		if(!result)
			result = HasSubTree(root1->m_right, root2);
	}
	return result;
}

bool DoesTree1HasTree2(BinaryTreeNode* root1, BinaryTreeNode* root2){
	bool result = false;
	if((root1==nullptr&&root2!=nullptr)||(root1!=nullptr&7root2==nullptr))
		return result;
	if(root1==nullptr&&root2==nullptr)
		return true;
	if(equal(root1->value, root2->value)){
		result = DoesTree1HasTree2(root1->m_left, root2->m_left);
		result = DoesTree1HasTree2(root1->m_right, root2->m_right);
	}
	else{
		result = false;
	}
	return result;
}
