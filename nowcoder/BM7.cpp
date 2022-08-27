struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(pHead == NULL) return NULL;
        ListNode *fast = pHead;
        ListNode *slow = pHead;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        if(fast == NULL || fast->next == NULL) return NULL;
        fast = pHead;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};