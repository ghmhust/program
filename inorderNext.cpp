//�������ĳһ������һ�ڵ㣬�и��ڵ㡣
class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL) return NULL;
		if (pNode->right){
			pNode = pNode->right;
			while (pNode->left != NULL)	pNode = pNode->left;
			return pNode;
		}
		else{
			TreeLinkNode* p = pNode;
			while (p->next){
				TreeLinkNode* q = p->next;
				if (q->left == p) return q;
				p = p->next;
			}
			return NULL;
		}
	}
};