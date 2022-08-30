/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

//���������ظ���Ԫ��ȫ��ɾ����ֻҪû�ظ����� 
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if(!pHead) return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = pHead;
        ListNode *tail = dummy,*p = pHead;
        while(p){
            if((p->next && p->val != p->next->val) || !p->next){//���p����һ���Ҳ���Ȼ򵽴�������β
                tail->next = p;
                tail = p;
            }  
            while(p->next && p->val == p->next->val) p = p->next;
            p = p->next;
        }
        tail->next = NULL;
        return dummy->next;
    }
};
