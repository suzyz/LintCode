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
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode * partition(ListNode * head, int x) {
        ListNode *left = new ListNode(0), *right = new ListNode(0);
    	ListNode *backup_l = left, *backup_r = right, *cur = head;
    	while (cur)
    	{
    		if (cur->val < x)
    		{
    			left->next = new ListNode(cur->val);
    			left = left->next;
    		}
    		else
    		{
    			right->next = new ListNode(cur->val);
    			right = right->next;
    		}
    		cur = cur->next;
    	}
    	left->next = backup_r->next;
    	return backup_l->left;
    }
};
