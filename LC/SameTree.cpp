/*给出两个二叉树，请写出一个判断两个二叉树是否相等的函数。 
判断两个二叉树相等的条件是：两个二叉树的结构相同，并且相同的节点上具有相同的值。*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


class Solution {
public:
	/**
	*
	* @param p TreeNode类
	* @param q TreeNode类
	* @return bool布尔型
	*/
	//注意区分迭代和递归
	bool isSameTree(TreeNode* p, TreeNode* q) {
		
		if (p != nullptr && q != nullptr && p->val == q->val)
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		else if (p == nullptr && q == nullptr)
			return true;
		else 
			return false;
	}
};