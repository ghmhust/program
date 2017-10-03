#include "stdio.h"
struct ListNode{
	int key;
	ListNode* next;
	ListNode(int pkey, ListNode* pnext) :key(pkey), next(pnext){

	}
};
void swap(int& a, int& b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}
ListNode* listquicksort(ListNode* head, ListNode* end){
	int val = head->key;
	ListNode* p = head;
	ListNode* q = head->next;
	while (q != end){
		if (q->key < val){
			p = p->next;
			swap(q->key, p->key);
		}
		q = q->next;
	}
	swap(p->key, head->key);
	return p;
}
void qsort(ListNode* head, ListNode* end){
	if (head != end){
		ListNode* cur = listquicksort(head, end);
		qsort(head, cur);
		qsort(cur->next, end);
	}
}
int main(){

}