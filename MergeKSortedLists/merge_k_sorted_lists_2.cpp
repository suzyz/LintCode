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
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int k = lists.size();
        if (k == 0)
        	return NULL;
        if (k == 1)
        	return lists[0];

        return merge_k_lists(0,k-1,lists);
    }

    ListNode *merge_k_lists(int st,int en,vector<ListNode *> &lists)
    {
    	if (st == en)
    		return lists[st];

        int mid = (st+en)>>1;

        return merge_two_lists(merge_k_lists(st,mid,lists),merge_k_lists(mid+1,en,lists));
    }

    ListNode *merge_two_lists(ListNode *a,ListNode *b)
    {
    	if (a==NULL)
    		return b;
    	if (b==NULL)
    		return a;

    	ListNode *res = new ListNode(0), *tmp;
    	ListNode *p = res;

    	while (a && b)
    	{
    		if (a->val < b->val)
    		{
    			tmp = a->next;
    			p->next = a;
    			a = tmp;
    		}
    		else
    		{
    			tmp = b->next;
    			p->next = b;
    			b = tmp;
    		}
    		p = p->next;
    	}
    	if (a)
    		p->next = a;
    	else
    		p->next = b;

    	return res->next;
    }
};
