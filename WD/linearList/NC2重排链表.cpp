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
    
    ListNode* reverse(ListNode *head){   //������ԭ������
        if(!head) return head;
        ListNode *dummy = new ListNode(-1);   //�Ӹ�ͷ
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
        if(!head || !head->next) return;  //�������ֻ��һ��Ԫ�أ�ֱ�ӷ��� 
        ListNode *slow = head,*fast = head,*preslow = head,*p;
        while(fast && fast->next){  //����ָ���ҵ������м�λ��
            preslow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        preslow->next = NULL;  //���м����
        fast = reverse(slow);  //���ú�벿�֣���ָ��ͷ
        preslow = head;  //ָ��ǰ�벿�ֿ�ͷ
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
