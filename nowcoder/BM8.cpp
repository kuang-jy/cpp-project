struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if(pHead == NULL) return pHead;
        ListNode *fast = pHead;
        ListNode *slow = pHead;
        //快指针先行k步
        while (k--)
        {
            //走不到k步，说明不存在倒数k个
            if(fast == NULL) return fast;
            fast = fast->next;
        }
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};