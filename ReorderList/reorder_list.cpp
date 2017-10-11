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
     * @param head: The head of linked list.
     * @return: nothing
     */
    void reorderList(ListNode * head) {
    	int n = 0;
        ListNode *cur = head, *res = new ListNode(0);
        while (cur != NULL)
        {
        	++n;
        	cur = cur->next;
        }
        int half = n/2;

        for (int i = 0; i < count; ++i)
        {
        	/* code */
        }
    }
};
