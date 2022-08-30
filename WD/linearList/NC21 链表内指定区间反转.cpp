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
     * @param m int���� 
     * @param n int���� 
     * @return ListNode��
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0);  //���ͷ���
        dummy->next = head;
        //Ѱ�ҷ�ת��ʼ��㣬����¼ǰ��
        ListNode *p = head,*pre;
        for(int i = 1;i<m;i++) {
            pre = p;
            p = p->next;
        }
        //��ʼ��ת
        for(int i = m;i <n;i++){
            ListNode *q = p->next;  //qָ��ʼ��ת�ڵ����һ���
            p->next = q->next;     
            q->next = pre->next;  //ָ����ת
            pre->next = q;  
        }
        return dummy->next;
    }
};
