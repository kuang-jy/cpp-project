/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

//将链表中重复的元素全部删掉，只要没重复过的 
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if(!pHead) return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = pHead;
        ListNode *tail = dummy,*p = pHead;
        while(p){
            if((p->next && p->val != p->next->val) || !p->next){//如果p有下一个且不相等或到达了链表尾
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
