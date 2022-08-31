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
	//逆转指针法 、指定区间逆转法 
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
	//头插法
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead || !pHead->next) return pHead;
        ListNode *dummy = new ListNode(-1);  //新链表表头
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
