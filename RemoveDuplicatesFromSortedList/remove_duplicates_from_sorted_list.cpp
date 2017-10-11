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
     * @param head: head is the head of the linked list
     * @return: head of linked list
     */
    ListNode * deleteDuplicates(ListNode * head) {
    	if (head == NULL || head->next == NULL)
    		return head;

       	if (head->val == head->next->val)
       	{
       		head->next = head->next->next;
       		return deleteDuplicates(head);
       	}
       	else
       	{
       		head->next = deleteDuplicates(head->next);
       		return head;
       	}
    }
};
