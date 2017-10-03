/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/

//·´×ªÁ´±í
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		ListNode* p = pHead;
		if (pHead == NULL || pHead->next == NULL) return p;
		ListNode* q = pHead->next;
		p->next = NULL;
		while (q){
			ListNode* cur = q;
			if (q->next){
				q = q->next;
				cur->next = p;
				p = cur;
			}
			else{
				q->next = p;
				break;
			}
		}
		return q;
	}
};