/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode * removeNthFromEnd(ListNode * head, int n) {
        ListNode *slow = head, *pre = head, *fast = head;
        for (int i = 0;i<n;++i)
            fast = fast->next;
        while (fast)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (slow == head)
            return head == NULL ? NULL:head->next;
            
        if (slow)
            pre->next = slow->next;
        return head;
    }
};