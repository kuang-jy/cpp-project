struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (pHead1 != NULL && pHead2 != NULL)
        {
            if (pHead1->val <= pHead2->val)
            {
                cur->next = pHead1;
                pHead1 = pHead1->next;
                cur = cur->next;
            }
            else{
                cur->next = pHead2;
                cur = cur->next;
                pHead2 = pHead2->next;
            }
        }
        cur->next = pHead1 == NULL ? pHead2 : pHead1 ;
        return dummy->next;        
    }
};