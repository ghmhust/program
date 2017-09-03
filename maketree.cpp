
//在中序遍历中找到根节点在递归.
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int prelen = pre.size();
		int inlen = vin.size();
		return maketree(pre, vin, 0, prelen - 1, 0, inlen - 1);
	}
	TreeNode* maketree(vector<int> pre, vector<int> vin, int prebegin, int preend, int inbegin, int inend){
		TreeNode* root = new TreeNode(pre[prebegin]);
		root->left = NULL;
		root->right = NULL;
		if (prebegin == preend) return root;
		int rootindex = 0;
		for (int i = 0; i <= preend; ++i){
			if (vin[i] == pre[prebegin]){
				rootindex = i;
			}
		}
		int leftlength = rootindex - inbegin;
		int leftpreend = prebegin + leftlength;
		if (leftlength>0){
			root->left = maketree(pre, vin, prebegin + 1, leftpreend, inbegin, rootindex - 1);
		}
		if (leftlength<preend - prebegin){
			root->right = maketree(pre, vin, leftpreend + 1, preend, rootindex + 1, inend);
		}
		return root;
	}
};