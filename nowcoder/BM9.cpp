struct ListNode {
	int val;
 	struct ListNode *next;
};


class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    //找到倒数第n个的前一个结点
    ListNode* findNth(ListNode* head, int n){
        if(head->next == NULL) return head;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre = NULL;
        while (n--)
        {
            if(fast == NULL) return fast;
            fast = fast->next;
        }
        while (fast)
        {
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        return pre;
    }
    //删除倒数第n个节点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = findNth(dummy,n);
        //倒数第n个节点的前序结点直接指向倒数第n个的下一个结点
        pre->next = pre->next->next;
        return dummy->next;
    }
};