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
     * @param head ListNode�� 
     * @return ListNode��
     */
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *pre = head,*p = head;  //pΪ����ָ�� 
        while(p){
            if(pre->val == p->val) pre->next = p->next;
            else pre = p;
            p = p->next;
        }
        return head;
    }
};
