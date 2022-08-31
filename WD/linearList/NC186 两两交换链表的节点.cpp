/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * 
     * @param head ListNode�� 
     * @return ListNode��
     */
     
     //�ݹ������������ 
    ListNode* swapLinkedPair(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *p = head->next;  //��ת���ͷ
        ListNode *nn = p->next;  //��¼��һ��Ŀ�ͷ
        p->next = head;  //��תָ�� 
        head->next = swapLinkedPair(nn);  //��ת���β��㣬ָ����һ�鷴ת���ͷ��� 
        return p;
    }
    
    //���������������
    //����ָ�����䷴ת������
    ListNode* swapLinkedPair(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy,*p = head,*q = p->next;
        while(p && q){  //�������������붼���ڣ��ſ��Խ��� 
            p->next = q->next;
            q->next = pre->next;
            pre->next = q;
            pre = p;
            p = p->next;
            q = p->next;
        }
        return dummy->next;
    } 
};
