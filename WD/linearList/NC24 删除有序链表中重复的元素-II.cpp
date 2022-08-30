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
     * @param head ListNode�� 
     * @return ListNode��
     */
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *dummy = new ListNode(-1);  //��ͷ���
        dummy->next = head;
        ListNode *p = head,*tail = dummy; //p���ڱ�������tail��¼��β
        while(p){
            if((p->next && p->next->val != p->val) || !p->next){ //��p����Ԫ�ز�ͬ �򵽴��β����ôp��������
                tail->next = p;  //β�������p
                tail = p;  //βָ�����
            }
            //�����ͬ����ôpһֱ���Ƶ���ͬΪֹ������Ϊ�˲������ظ�����Ԫ�أ���while��pҪ�ٴκ���
            while(p->next && p->val == p->next->val) p = p->next;
            p = p->next;
        }
        tail->next = NULL;
        return dummy->next;
    }
};
