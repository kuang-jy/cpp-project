/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode *head){   //将链表原地逆置
        if(!head) return head;
        ListNode *dummy = new ListNode(-1);   //加个头
        ListNode *p = head,*q;
        while(p){
            q = p->next;
            p->next = dummy->next;
            dummy->next = p;
            p = q;
        }
        return dummy->next;
    }
    
    void reorderList(ListNode *head) {
        if(!head || !head->next) return;  //空链表或只有一个元素，直接返回 
        ListNode *slow = head,*fast = head,*preslow = head,*p;
        while(fast && fast->next){  //快慢指针找到链表中间位置
            preslow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        preslow->next = NULL;  //从中间断链
        fast = reverse(slow);  //逆置后半部分，并指向开头
        preslow = head;  //指向前半部分开头
        slow = NULL;
        while(preslow){
            p = fast->next;
            fast->next = preslow->next;
            preslow->next = fast;
            preslow = fast->next;
            slow = fast;
            fast = p;
        }
        if(fast) slow->next = fast;
    }
};
