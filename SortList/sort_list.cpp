/* Use merge sort to sort a list. */

#include <cstdio>
#include <iostream>
using namespace std;

class ListNode {
 public:
     int val;
     ListNode *next;
     ListNode(int val) {
         this->val = val;
         this->next = NULL;
    }
};

class Solution {
public:
    /*
     * @param head: The head of linked list.
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */

	ListNode * merge(ListNode *l,ListNode *r)
	{
		if (l == NULL)
			return r;
		if (r == NULL)
			return l;

		if (l->val < r->val)
		{
			l->next = merge(l->next,r);
			return l;
		}
		else
		{
			r->next = merge(l,r->next);
			return r;
		}
	}

    ListNode * sortList(ListNode * head) {
        if (head == NULL || head->next == NULL)
        	return head;
        
        ListNode *pre = head, *l = head, *r = head;
		while (r != NULL && r->next != NULL)
		{
			pre = l;
			l = l->next;
			r = r->next->next;
		}
		pre->next = NULL;

		return merge(sortList(head),sortList(l));
    }
};

int main(int argc, char const *argv[])
{
	ListNode *l = new ListNode(1);
	l -> next = new ListNode(3);
	l -> next->next = new ListNode(2);

	Solution s;
	ListNode *res = s.sortList(l);

	while(res)
	{
		cout<<"res:" << res->val << endl;
		res = res->next;
	}
	return 0;
}