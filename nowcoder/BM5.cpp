//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    //合并两个列表
    ListNode *merge2(ListNode *head1,ListNode *head2){
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->val <= head2->val)
            {
                cur->next = head1;
                cur = cur->next;
                head1 = head1->next;
            }
            else{
                cur->next = head2;
                cur = cur->next;
                head2 = head2->next;
            }
        }
        cur->next = head1 == NULL ? head2 : head1;
        return dummy->next;
    }

    ListNode *divideList(vector<ListNode *> &lists,int l,int r){
        //空数组特判
        if(l > r) return NULL;
        //正常递归边界
        if(l == r) return lists[l];
        int mid = (l+r)/2;
        ListNode *left = divideList(lists,l,mid);
        ListNode *right = divideList(lists,mid+1,r);
        return(merge2(left,right));
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return divideList(lists,0,lists.size()-1);
    }
};