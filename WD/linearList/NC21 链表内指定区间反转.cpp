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
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0);  //添加头结点
        dummy->next = head;
        //寻找反转开始结点，并记录前驱
        ListNode *p = head,*pre;
        for(int i = 1;i<m;i++) {
            pre = p;
            p = p->next;
        }
        //开始反转
        for(int i = m;i <n;i++){
            ListNode *q = p->next;  //q指向开始反转节点的下一结点
            p->next = q->next;     
            q->next = pre->next;  //指针逆转
            pre->next = q;  
        }
        return dummy->next;
    }
};
