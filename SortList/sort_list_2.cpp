/* Use quick sort to sort a list. TLE */

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
	void set_list_free(ListNode * head)
	{
		if (head == NULL)
			return;
		set_list_free(head->next);
		delete head;
	}
    ListNode * sortList(ListNode * head) {
        int n = 0;
        if (head == NULL || head->next == NULL)
        	return head;

        int v = head->val;
        ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0);
        ListNode *p = left, *q = right;
        ListNode *cur = head->next;

       	while(cur)
       	{
       		if (cur->val < v)
       		{
       			p->next = new ListNode(cur->val);
       			p = p->next;
       		}
       		else
       		{
       			q->next = new ListNode(cur->val);
       			q = q->next;
       		}
       		cur = cur->next;
       	}

       	set_list_free(head);

       	cur = sortList(left->next);
       	delete left;
       	left = cur;

       	cur = sortList(right->next);
       	delete right;
       	right = new ListNode(v);
		right->next = cur;

       	if (left == NULL)
       		return right;

        ListNode *pre = left;
        cur = left;
        while (cur)
        {
        	pre = cur;
        	cur = cur->next;
        }
       	pre->next = right;
        
        return left;
    }
};

int main(int argc, char const *argv[])
{
	ListNode *l = new ListNode(2);
	l -> next = new ListNode(-1);
	l -> next->next = new ListNode(0);

	Solution s;
	ListNode *res = s.sortList(l);

	while(res)
	{
		cout<<"res:" << res->val << endl;
		res = res->next;
	}
	return 0;
}