#include <vector>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
 };


class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        if(head == NULL) return false;
        if(head->next == NULL) return true;
        vector<int> list;
        ListNode* cur = head;
        while (cur)
        {
            list.push_back(cur->val);
            cur = cur->next;
        }
        int front = 0;
        int tail = list.size()-1;
        while (front <= tail)
        {
            if(list[front++] != list[tail--]) return false;
        }
        return true;
    }
};