//删除链表中相同的节点
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode* out = new ListNode(0);
		ListNode* p = out;
		ListNode* q = pHead;
		while (q){
			if (q->next && q->val == q->next->val){
				ListNode* qnew = q->next;
				while (qnew->next && qnew->val == qnew->next->val){
					qnew = qnew->next;
				}
				q = qnew->next;
			}
			else{
				p->next = q;
				p = p->next;
				q = q->next;
			}
		}
		p->next = NULL;
		return out->next;
	}
};