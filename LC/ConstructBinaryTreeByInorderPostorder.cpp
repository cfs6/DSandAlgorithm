/*给出一棵树的中序遍历和后序遍历，请构造这颗二叉树 
注意： 
保证给出的树中不存在重复的节点 */
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
	* @param inorder int整型vector
	* @param postorder int整型vector
	* @return TreeNode类
	*/
	//数组中多用角标（i,j,x,y）参数表示每层递归参数（确定数组长度）
	TreeNode* connectNode(vector<int>inorder,int x, int y,vector<int> postorder,
		int i, int j)
	{
		//注意结束递归的判断
		if (x > y || i > j)
			return nullptr;
		TreeNode* root = new TreeNode(postorder[j]);
		for (int k = x; k <= y; ++k)
		{
			if (inorder[k] == postorder[j])
			{
				root->left = connectNode(inorder, x, k - 1, postorder, i, i + k - 1 - x);
				root->right = connectNode(inorder, k + 1, y, postorder, i + k - x, j-1);
				break;
			}
		}
		return root;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0 || postorder.size() == 0 || inorder.size() != postorder.size())
		{
			return nullptr;
		}
		int inSize = inorder.size();
		int postSize = postorder.size();
		return connectNode(inorder, 0, inSize - 1, postorder, 0, postSize - 1);

	}
};

4526731
4251637