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
        ListNode *dummy = new ListNode(-1);  //加头结点
        dummy->next = head;
        ListNode *p = head,*tail = dummy; //p用于遍历链表，tail记录表尾
        while(p){
            if((p->next && p->next->val != p->val) || !p->next){ //若p相邻元素不同 或到达表尾，那么p可以留下
                tail->next = p;  //尾结点连结p
                tail = p;  //尾指针后移
            }
            //如果相同，那么p一直后移到不同为止，并且为了不保留重复过的元素，在while后p要再次后移
            while(p->next && p->val == p->next->val) p = p->next;
            p = p->next;
        }
        tail->next = NULL;
        return dummy->next;
    }
};
