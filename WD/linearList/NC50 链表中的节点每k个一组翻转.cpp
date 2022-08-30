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
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tail = head;
        for(int i = 1;i <= k;i++)
            if(!tail) return head;  //如果不够k个，直接返回
            else tail = tail->next; //继续找
        ListNode *p = head,*pre = NULL;
        for(int i = 0;i < k;i++){  //与区间反转不同！！ 
            ListNode *q = p->next;
            p->next = pre;
            pre = p;
            p = q;
        }
        head->next = reverseKGroup(tail, k);
        return pre;
    }
};
