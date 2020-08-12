/*给出一棵树的前序遍历和中序遍历，请构造这颗二叉树 
注意： 
可以假设树中不存在重复的节点 */
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int val_) :val(val_) {}
};


class Solution {
public:
	/**
	*
	* @param preorder int整型vector
	* @param inorder int整型vector
	* @return TreeNode类
	*/
	TreeNode* connectNode(vector<int>& preorder, int x, int y,
		vector<int>& inorder, int i, int j)
	{
		if (x > y || i > j)
			return nullptr;
		TreeNode* root = new TreeNode(preorder[x]);
		for (int k = i; k <= j; ++k)
		{
			if (preorder[x] == inorder[k])
			{
				root->left = connectNode(preorder, x+1, x+k-i, inorder,i,k-1);
				root->right = connectNode(preorder, x+k-i+1, y, inorder, k + 1, j);
				break;
			}
		}
		return root;
	}


	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size())
			return nullptr;
		return connectNode(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
};