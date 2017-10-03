/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/

//两个不减链表合并成一个链表
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (!pHead2) return pHead1;
		if (!pHead1) return pHead2;
		ListNode* head = NULL;
		if (pHead1->val <= pHead2->val){
			head = pHead1;
			if (pHead1->next)
				pHead1 = pHead1->next;
			else{
				pHead1->next = pHead2;
				return head;
			}
		}
		else{
			head = pHead2;
			if (pHead2->next)
				pHead2 = pHead2->next;
			else{
				pHead2->next = pHead1;
				return head;
			}
		}
		ListNode* p = head;
		merge(pHead1, pHead2, p);
		return head;
	}
	void merge(ListNode* pHead1, ListNode* pHead2, ListNode* p){
		if (pHead1->val <= pHead2->val){
			p->next = pHead1;
			p = p->next;
			if (pHead1->next){
				pHead1 = pHead1->next;
				merge(pHead1, pHead2, p);
			}
			else{
				p->next = pHead2;
			}
		}
		else{
			p->next = pHead2;
			p = p->next;
			if (pHead2->next){
				pHead2 = pHead2->next;
				merge(pHead1, pHead2, p);
			}
			else{
				p->next = pHead1;
			}
		}
	}
};