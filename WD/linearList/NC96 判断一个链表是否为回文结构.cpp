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
     * @param head ListNode�� the head
     * @return bool������
     */
     
     //���ÿ���ָ���ҵ������м�ڵ㣬�ٷ�ת��벿�֣����αȽϣ�ע������ʱslow����һ���� 
    
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
        if(fast) slow = slow->next;  //�������������slow��Ҫ����һ��
        //slowָ���벿�ֵĿ�ͷ
        preslow->next = NULL; //�м�Ͽ�
        preslow = rev(slow);  //��ת��벿��
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
