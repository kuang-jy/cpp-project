#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
};

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur = head;
        //找到开始反转的位置
        for (size_t i = 0; i < m-1; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        for (size_t i = m; i < n; i++)
        {
            ListNode *temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return dummy->next;
    }
};