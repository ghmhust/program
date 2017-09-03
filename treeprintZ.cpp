//之字型打印二叉树

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<int> temp;
		vector<vector<int> >out;
		if (pRoot == NULL) return out;
		stack<TreeNode*>st[2];
		TreeNode* last = pRoot;
		TreeNode* var = NULL;
		st[0].push(pRoot);
		while (!st[0].empty() || !st[1].empty()){
			while (!st[0].empty()){
				var = st[0].top();
				temp.push_back(var->val);
				if (var->left)	st[1].push(var->left);
				if (var->right)	st[1].push(var->right);
				st[0].pop();
			}
			if (temp.size()>0)
				out.push_back(temp);
			temp.clear();
			while (!st[1].empty()){
				var = st[1].top();
				temp.push_back(var->val);
				if (var->right)	st[0].push(var->right);
				if (var->left)	st[0].push(var->left);
				st[1].pop();
			}
			if (temp.size()>0)
				out.push_back(temp);
			temp.clear();
		}
		return out;
	}
};