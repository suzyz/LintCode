/* Use merge sort to sort a list.
The merge() function isn't recursive in this edition. */

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
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */
	void set_free(ListNode *p)
	{
		if (p==NULL)
			return;
		set_free(p->next);
		delete p;
	}
	ListNode * merge(ListNode *l,ListNode *r)
	{
		ListNode *p = l, *q = r;
		ListNode *res = new ListNode(0);
		ListNode *head = res;
		
		while (p!= NULL && q!= NULL)
		{
			if (p->val < q->val)
			{
				res->next = new ListNode(p->val);
				p = p->next;
			}
			else
			{
				res->next = new ListNode(q->val);
				q = q->next;
			}
			res = res->next;
		}
		while (p!=NULL)
		{
			res->next = new ListNode(p->val);
			res = res->next;
			p = p->next;
		}
		while (q!=NULL)
		{
			res->next = new ListNode(q->val);
			res = res->next;
			q = q->next;
		}

		set_free(l);
		set_free(r);
		return head->next;
	}
	ListNode * merge_sort(ListNode *head,int n)
	{
		if (n<=1)
			return head;

		ListNode *pre = head, *mid = head;
		for (int i = 0; i < n/2; ++i)
		{
			pre = mid;
			mid = mid->next;
		}
		pre->next = NULL;

		ListNode *l = merge_sort(head,n/2);
		ListNode *r = merge_sort(mid,n-n/2);

		return merge(l,r);
	}
    ListNode * sortList(ListNode * head) {
        int n = 0;
        if (head == NULL)
        	return 0;
        ListNode *p = head;
        while (p)
        {
        	++n;
        	p = p->next;
        }
        return merge_sort(head,n);
    }
};