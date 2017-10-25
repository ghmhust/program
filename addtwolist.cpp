#include <iostream>
#include <queue>
/*
 * leetcode 2017.10.25
 * add two sort list
 * */
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        queue<int> s1,s2;
        while(l1 || l2){
            if(l1){
                s1.push(l1->val);
                l1 = l1->next;
            }
            else s1.push(0);
            if(l2){
                s2.push(l2->val);
                l2 = l2->next;
            }
            else s2.push(0);
        }
        ListNode* p = new ListNode(0);
        ListNode* head = p;
        int var = 0;
        int flag = 1;
        while(!s1.empty() && !s2.empty()){
            int res = s1.front()+s2.front()+var;
            s1.pop();
            s2.pop();
            if(res>9){
                var = 1;
                ListNode* temp = new ListNode(res-10);
                p->next = temp;
                p = p->next;
            }
            else{
                var = 0;
                ListNode* temp = new ListNode(res);
                p->next = temp;
                p = p->next;
            }
            if(flag){
                head = p;
                flag = 0;
            }
        }
        if(var == 1){
            ListNode* temp = new ListNode(1);
            p->next = temp;
            p = p->next;
        }
        p->next = NULL;
        return head;
    }

int main() {
    cout << "Hello, World!" << std::endl;
    return 0;
}