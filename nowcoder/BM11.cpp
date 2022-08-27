// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     };


class Solution {
public:
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */

    ListNode* reverseList(ListNode *head){
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = NULL;
        ListNode *next = head;
        while (next)
        {
            cur = next;
            next = next->next;
            cur->next = dummy->next;
            dummy->next = cur;
        }
        return dummy->next;
    }

    ListNode* addInList(ListNode* head1, ListNode* head2) {
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        ListNode *rHead1 = reverseList(head1);
        ListNode *rHead2 = reverseList(head2);
        int tag = 0;
        while (rHead1 || rHead2)
        {
            int val1 = rHead1 ? rHead1->val : 0 ;
            int val2 = rHead2 ? rHead2->val : 0 ;
            int add = val1+val2+tag;
            tag = add/10;
            add%=10;
            cur->next = new ListNode(add);
            cur = cur->next;
            rHead1 = rHead1 ? rHead1->next : NULL;
            rHead2 = rHead2 ? rHead2->next : NULL;            
        }
        if(tag) cur->next = new ListNode(tag);
        return(reverseList(dummy->next));
    }
};