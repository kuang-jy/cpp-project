/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	//��תָ�뷨 ��ָ��������ת�� 
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead || !pHead->next) return pHead;
        ListNode *p = pHead,*pre = NULL,*temp;
        while(p){
            temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
        }
        return pre;
    }
	//ͷ�巨
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead || !pHead->next) return pHead;
        ListNode *dummy = new ListNode(-1);  //�������ͷ
        dummy->next = NULL;  
        ListNode *p = pHead,*temp;
        while(p){
            temp = p->next;
            p->next = dummy->next;
            dummy->next = p;
            p = temp;
        }
        return dummy->next;
    } 
};
