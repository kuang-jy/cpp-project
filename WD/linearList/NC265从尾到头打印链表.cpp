/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    
    void getReverse(ListNode *head,vector<int>& ans){
        if(!head) return;
        getReverse(head->next, ans);
        ans.push_back(head->val);
    }
    
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ans;
        getReverse(head, ans);
        return ans;
    }
};
