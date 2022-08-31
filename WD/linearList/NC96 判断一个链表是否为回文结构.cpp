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
     * @param head ListNode类 the head
     * @return bool布尔型
     */
     
     //先用快慢指针找到链表中间节点，再反转后半部分，依次比较（注意奇数时slow多走一步） 
    
    ListNode* rev(ListNode* head){
        ListNode *pre = NULL,*p = head,*temp;
        while(p){
            temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
            temp = temp->next;
        }
        return pre;
    }
    
    bool isPail(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow = head,*fast = head,*preslow;
        while(fast && fast->next){
            preslow = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast) slow = slow->next;  //如果是奇数个，slow需要再走一步
        //slow指向后半部分的开头
        preslow->next = NULL; //中间断开
        preslow = rev(slow);  //逆转后半部分
        while(preslow){
            if(head->val == preslow->val){
                head = head->next;
                preslow = preslow->next;
            }
            else return false;
        }
        return true;
    }
};
