//前序遍历和自定义前序遍历是否相等
class Solution {
public:
	vector<string> temp;
	vector<string> temp1;
	void preorder(TreeNode* pRoot){
		temp.push_back(to_string(pRoot->val));
		if (pRoot->left) preorder(pRoot->left);
		else temp.push_back("#");
		if (pRoot->right) preorder(pRoot->right);
		else temp.push_back("#");
	}
	void preorder1(TreeNode* pRoot){
		temp1.push_back(to_string(pRoot->val));
		if (pRoot->right) preorder1(pRoot->right);
		else temp1.push_back("#");
		if (pRoot->left) preorder1(pRoot->left);
		else temp1.push_back("#");
	}
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL) return true;
		preorder(pRoot);
		preorder1(pRoot);
		int len = temp.size();
		for (int i = 0; i<len; ++i){
			if (temp[i] != temp1[i])
				return false;
		}
		return true;
	}
};