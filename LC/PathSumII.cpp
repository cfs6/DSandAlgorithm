/*����һ����������һ��ֵsum��
���ҳ����еĸ��ڵ㵽Ҷ�ӽڵ�Ľڵ�ֵ֮�͵���sum��·��*/
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


class Solution {
public:
	/**
	*
	* @param root TreeNode��
	* @param sum int����
	* @return int����vector<vector<>>
	*/
	//���ü��������βε�ʹ�ý���˵ݹ���res�Ļ�������
	//resÿ��ͨ���������ã��Ḵ��һ���µ�vector�������
	void dfs(TreeNode* root, int sum, vector<int> res, vector<vector<int>>& result)
	{
		if (root == nullptr)
			return;
		res.push_back(root->val);
		if (root->val == sum && root->left == nullptr && root->right == nullptr)
		{
			result.push_back(res);
		}
		dfs(root->left, sum - root->val, res, result);

		dfs(root->right, sum - root->val, res, result);
	}
	vector<vector<int> > pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> res;
		dfs(root, sum, res, result);
		return result;
	}
};