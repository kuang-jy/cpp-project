struct ListNode {
	int val;
	struct ListNode *next;
    };


class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head node
     * @return ListNode类
     */

    //合并两个已排序链表
    ListNode* merge2(ListNode* head1,ListNode* head2){
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (head1 != NULL && head2 != NULL)
        {
            if(head1->val <= head2->val) {
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
        cur->next = head1 ? head1 : head2;
        return dummy->next;
    }

    ListNode* sortInList(ListNode* head) {
        //如果链表为空或只有一个结点，则认为是有序的，直接返回
        if(head == NULL || head->next == NULL) return head;
        //快慢指针查找mid
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        //从中间将链表断开
        slow->next = NULL;
        return(merge2(sortInList(head),sortInList(temp)));
    }
};