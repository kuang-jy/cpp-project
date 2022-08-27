struct ListNode {
	int val;
	struct ListNode *next;
 };


class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next && cur->next->next)
        {
            if (cur->next->val == cur->next->next->val)
            {
                int temp = cur->next->val;
                while(cur->next != NULL && cur->next->val == temp) 
                    cur->next = cur->next->next;
            }
            else cur = cur->next;
        }
        return dummy->next;
    }
};