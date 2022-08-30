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
    
    //һ�˻���
    ListNode* partition(ListNode* low,ListNode* high){
        int pivot = low->val;  //ѡȡ��һ��Ԫ��Ϊ����
        ListNode *p = low,*q = low->next;
        while(q!=high){    //��������С�Ļ���ǰ�� 
            if(q->val < pivot) {
                p = p->next;
                swap(q->val,p->val);
            }
            q = q->next;
        }
        swap(low->val, p->val);  //�����ỻ���м� 
        return p;
    }
    
    void qsort(ListNode *low,ListNode* high){
        if(low ==high) return;
        ListNode* pivot = partition(low,high);
        qsort(low, pivot);
        qsort(pivot->next, high);
    }
    
    ListNode* sortInList(ListNode* head) {
        qsort(head,NULL);
        return head;
    }
};
