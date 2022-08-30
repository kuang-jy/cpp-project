/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *pre = head,*p = head;  //p为工作指针 
        while(p){
            if(pre->val == p->val) pre->next = p->next;
            else pre = p;
            p = p->next;
        }
        return head;
    }
};
