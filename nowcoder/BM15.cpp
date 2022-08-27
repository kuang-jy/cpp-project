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
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast)
        {
            if(slow->val != fast->val){
                slow->next = fast;
                slow = fast;
            }
            slow->next = fast->next;
            fast = fast->next;
        }
        return head;
    }
};