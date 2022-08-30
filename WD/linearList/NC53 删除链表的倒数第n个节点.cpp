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
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;  //加个头
        ListNode *fast = dummy,*slow = dummy;  //快慢指针找到倒数第n个
        ListNode *pre;  //pre记录倒数第n个结点的前驱
        for(int i = 0;i < n;i++)  //快指针先行n步
            if(!fast) return head;  //不存在倒数第n个
            else fast = fast->next;
        while(fast){  //slow指向倒数第n个
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = slow->next;
        return dummy->next;
    }
};
