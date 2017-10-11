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
     * @param l1: ListNode l1 is the head of the linked list
     * @param l2: ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        ListNode *res = new ListNode(0);
        ListNode *backup = res;

        while (l1 != NULL && l2 != NULL)
        {
        	if (l1->val < l2->val)
        	{
        		res->next = new ListNode(l1->val);
        		l1 = l1->next;
        	}
        	else
        	{
        		res->next = new ListNode(l2->val);
        		l2 = l2->next;
        	}
        	res = res->next;
        }
        if (l1 != NULL)
        	res->next = l1;
        else
        if (l2 != NULL)
        	res->next = l2;
        return backup->next;
    }
};
