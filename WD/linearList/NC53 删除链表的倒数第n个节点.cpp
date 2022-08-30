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
     * @param n int���� 
     * @return ListNode��
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;  //�Ӹ�ͷ
        ListNode *fast = dummy,*slow = dummy;  //����ָ���ҵ�������n��
        ListNode *pre;  //pre��¼������n������ǰ��
        for(int i = 0;i < n;i++)  //��ָ������n��
            if(!fast) return head;  //�����ڵ�����n��
            else fast = fast->next;
        while(fast){  //slowָ������n��
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = slow->next;
        return dummy->next;
    }
};
