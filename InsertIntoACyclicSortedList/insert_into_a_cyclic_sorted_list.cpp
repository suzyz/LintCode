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
     * @param node: a list node in the list
     * @param x: An integer
     * @return: the inserted new list node
     */
    ListNode * insert(ListNode * node, int x) {
    	ListNode *cur = new ListNode(x);
        if (node == NULL)
        {
            cur->next = cur;
            return cur;         
        }

        if (node->next == node)
        {
            node->next = cur;
            cur->next = node;
            return node;
        }

    	ListNode *p = node, *tmp;
        int count = 0;
        while (p && count < 2)
        {
            if (p == node)
                ++count;

            if (x >= p->val && x <= p->next->val)
            {
                tmp = p->next;
                p->next = cur;
                cur->next = tmp;
                return node;
            }

            if (p->val > p->next->val && (x >= p->val || x <= p->next->val))
            {
                tmp = p->next;
                p->next = cur;
                cur->next = tmp;
                return node;
            }

            p = p->next;
        }

        tmp = node->next;
        node->next = cur;
        cur->next = tmp;
        return node;
    }
};
