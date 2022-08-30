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
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    
    //一趟划分
    ListNode* partition(ListNode* low,ListNode* high){
        int pivot = low->val;  //选取第一个元素为枢轴
        ListNode *p = low,*q = low->next;
        while(q!=high){    //将比枢轴小的换到前面 
            if(q->val < pivot) {
                p = p->next;
                swap(q->val,p->val);
            }
            q = q->next;
        }
        swap(low->val, p->val);  //将枢轴换到中间 
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
