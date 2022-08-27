#include <iostream>

 struct ListNode {
 int val;
 struct ListNode *next;
 };
 

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        //找到每次反转的尾部，下组的头结点
        ListNode *tail = head;
        for (size_t i = 0; i < k; i++)
        {
            tail = tail->next;
            if(tail == NULL) return head;
        }
        //反转操作
        ListNode *cur = head;
        ListNode *pre = NULL;
        while(cur != tail){
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        //原本头结点，即组内反转后的尾结点指向下一组反转后的头结点
        head->next = reverseKGroup(tail,k);
        //返回反转后的头结点
        return pre;
    }
};