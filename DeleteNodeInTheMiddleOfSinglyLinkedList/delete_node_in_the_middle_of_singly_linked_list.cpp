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
     * @param node: the node in the list should be deletedt
     * @return: nothing
     */
    void deleteNode(ListNode * node) {
    	ListNode *p = node, *pre = node;
    	while (p && p->next)
    	{
    		p->val = p->next->val;
    		pre = p;
    		p = p->next;
    	}
    	pre->next = NULL;
    }
};
