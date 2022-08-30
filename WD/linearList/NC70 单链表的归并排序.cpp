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
     * @param head ListNode�� the head node
     * @return ListNode��
     */
    //������Ĺ鲢����
    ListNode* merge(ListNode *l1,ListNode *l2){   //�ϲ�������������
        if(!l1) return l2;
        if(!l2) return l1;  //�ձ�����
        ListNode *dummy = new ListNode(-1);  //�±�ͷ
        ListNode *p = dummy;   //��βָ�빤��ָ��
        while(l1 && l2){
            if(l1->val <= l2->val){
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;  //βָ�����
        }
        p->next = l1 ? l1 : l2;
        return dummy->next;
    }
    
    ListNode* sortInList(ListNode* head) {
        if(!head || !head->next) return head;  //�ձ���Ԫ�ر�����
        ListNode *slow = head,*fast = head->next;   //����ָ��Ѱ���м�ڵ�
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;  //��¼��벿�ֵĿ�ͷ
        slow->next = NULL;   //�Ͽ�����
        return merge(sortInList(head),sortInList(fast));
    }
};
