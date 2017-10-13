/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param head: the List
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode * rotateRight(ListNode * head, int k) {
    	if (head == NULL || head->next == NULL)
    		return head;

        ListNode *p = head,*pre = head;
        int n = 0;
        while (p)
        {
        	++n;
        	pre = p;
        	p = p->next;
        }
        k %= n;
        if (k == 0)
        	return head;

        pre->next = head;

        p = pre = head;
        for (int i = 0; i < n-k; ++i)
        {
        	pre = p;
        	p = p->next;
        }
        pre->next = NULL;
        return p;
    }
};
