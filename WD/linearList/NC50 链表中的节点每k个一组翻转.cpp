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
     * @param k int���� 
     * @return ListNode��
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tail = head;
        for(int i = 1;i <= k;i++)
            if(!tail) return head;  //�������k����ֱ�ӷ���
            else tail = tail->next; //������
        ListNode *p = head,*pre = NULL;
        for(int i = 0;i < k;i++){  //�����䷴ת��ͬ���� 
            ListNode *q = p->next;
            p->next = pre;
            pre = p;
            p = q;
        }
        head->next = reverseKGroup(tail, k);
        return pre;
    }
};
