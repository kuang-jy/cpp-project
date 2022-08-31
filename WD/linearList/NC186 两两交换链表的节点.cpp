/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
     
     //递归完成两两交换 
    ListNode* swapLinkedPair(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *p = head->next;  //反转后的头
        ListNode *nn = p->next;  //记录下一组的开头
        p->next = head;  //反转指针 
        head->next = swapLinkedPair(nn);  //反转后的尾结点，指向下一组反转后的头结点 
        return p;
    }
    
    //遍历完成两两交换
    //类似指定区间反转的做法
    ListNode* swapLinkedPair(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy,*p = head,*q = p->next;
        while(p && q){  //后面两个结点必须都存在，才可以交换 
            p->next = q->next;
            q->next = pre->next;
            pre->next = q;
            pre = p;
            p = p->next;
            q = p->next;
        }
        return dummy->next;
    } 
};
