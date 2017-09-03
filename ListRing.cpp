//环形链表第一个入口
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL) return NULL;
		ListNode* fast = pHead;
		ListNode* slow = pHead;
		while (slow->next && slow->next){
			if (fast->next->next)
				fast = fast->next->next;
			else return NULL;
			if (slow->next)
				slow = slow->next;
			else return NULL;
			if (fast == slow) break;
		}
		if (fast == slow){
			slow = pHead;
			while (fast != slow){
				fast = fast->next;
				slow = slow->next;
			}
			return slow;
		}
		return NULL;
	}
};