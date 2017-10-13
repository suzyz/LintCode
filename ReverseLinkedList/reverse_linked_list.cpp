/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode * reverse(ListNode * head) {
        if (head == NULL || head->next == NULL)
        	return head;

        ListNode *p = head, *q = head->next, *tmp;
        while(q)
        {
        	tmp = q->next;
        	q->next = p;

        	p = q;
        	q = tmp;
        }
        head->next = NULL;
        return p;
    }
};