//二叉搜索树第k大的节点
class Solution {
public:
	void inorder(TreeNode* pRoot, vector<TreeNode*> &out){
		if (pRoot->left)
			inorder(pRoot->left, out);
		out.push_back(pRoot);
		if (pRoot->right)
			inorder(pRoot->right, out);
	}

	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == NULL || k <= 0)	return NULL;
		vector<TreeNode*> out;
		inorder(pRoot, out);
		if (k>out.size()) return NULL;
		return out[k - 1];
	}
};