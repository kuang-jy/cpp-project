#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL || pHead->next == NULL) return pHead;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        ListNode *next = pHead;
        while(next != NULL){
            cur = next;
            next = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
        }
        return dummy->next;
    }
};