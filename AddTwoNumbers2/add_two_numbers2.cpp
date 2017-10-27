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
     * @param l1: The first list.
     * @param l2: The second list.
     * @return: the sum list of l1 and l2.
     */
    ListNode * addLists2(ListNode * l1, ListNode * l2) {

    	ListNode *p = reverse_list(l1), *q = reverse_list(l2);
    	ListNode *ans = new ListNode(0);
    	ListNode *cur = ans;

    	int carry = 0;
    	while (p && q)
    	{
    		int d = p->val + q->val + carry;
    		carry = d/10;
    		cur->next = new ListNode(d%10);

    		cur = cur->next;
   			p = p->next;
   			q = q->next;
    	}
    	while (p)
    	{
    		int d = p->val + carry;
    		carry = d/10;
    		cur->next = new ListNode(d%10);

    		cur = cur->next;
   			p = p->next;
    	}
    	while (q)
    	{
    		int d = q->val + carry;
    		carry = d/10;
    		cur->next = new ListNode(d%10);

    		cur = cur->next;
   			q = q->next;
    	}
    	if (carry)
    		cur->next = new ListNode(carry);
    	return reverse_list(ans->next);
    }

    ListNode * reverse_list(ListNode *l)
    {
    	ListNode *p = l , *q, *new_l = NULL;
    	while (p)
    	{
    		q = new ListNode(p->val);
    		q->next = new_l;
    		new_l = q;
    		
    		p = p->next;
    	}
    	return new_l;
    }
};
