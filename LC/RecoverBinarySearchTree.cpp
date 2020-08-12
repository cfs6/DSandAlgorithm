/*������������BST���е������ڵ㱻����ؽ����ˣ�
���ڲ��ı����Ľṹ������»ָ��������  */

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	
	TreeNode *node1 = nullptr;
	TreeNode* node2 = nullptr;
	TreeNode* pre = nullptr;
	void recoverTree(TreeNode *root) {
		if (root == nullptr)
			return;
		dfs(root);
		if(node1 && node2)
			swap(node1->val, node2->val);
	}

	void dfs(TreeNode* root)
	{
		if (root == nullptr)
			return;
		dfs(root->left);
		if (pre != nullptr && pre->val > root->val)
		{
			if (!node1)
				node1 = pre;
			node2 = root; 
		}
		pre = root;
		dfs(root->right);
	}
};