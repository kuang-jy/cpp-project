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
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    //单链表的归并排序
    ListNode* merge(ListNode *l1,ListNode *l2){   //合并两个有序链表
        if(!l1) return l2;
        if(!l2) return l1;  //空表特判
        ListNode *dummy = new ListNode(-1);  //新表头
        ListNode *p = dummy;   //队尾指针工作指针
        while(l1 && l2){
            if(l1->val <= l2->val){
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;  //尾指针后移
        }
        p->next = l1 ? l1 : l2;
        return dummy->next;
    }
    
    ListNode* sortInList(ListNode* head) {
        if(!head || !head->next) return head;  //空表，单元素表特判
        ListNode *slow = head,*fast = head->next;   //快慢指针寻找中间节点
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;  //记录后半部分的开头
        slow->next = NULL;   //断开链表
        return merge(sortInList(head),sortInList(fast));
    }
};
