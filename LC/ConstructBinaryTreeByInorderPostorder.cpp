/*����һ��������������ͺ���������빹����Ŷ����� 
ע�⣺ 
��֤���������в������ظ��Ľڵ� */
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
	* @param inorder int����vector
	* @param postorder int����vector
	* @return TreeNode��
	*/
	//�����ж��ýǱ꣨i,j,x,y��������ʾÿ��ݹ������ȷ�����鳤�ȣ�
	TreeNode* connectNode(vector<int>inorder,int x, int y,vector<int> postorder,
		int i, int j)
	{
		//ע������ݹ���ж�
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