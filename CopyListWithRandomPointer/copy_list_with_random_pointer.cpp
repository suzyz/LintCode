#include <iostream>
#include <cstdio>


/**
 * Definition for singly-linked list with a random pointer.
 */
  struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };

class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if (head == NULL)
    		return NULL;
        RandomListNode *p = head,*tmp;
        while (p)
        {
        	tmp = p->next;
        	p->next = new RandomListNode(p->label);
        	p->next->next = tmp;
        	p = p->next->next;
        }
        
        p = head;
        while (p)
        {
     		if (p->random == NULL)
     			p->next->random = NULL;
     		else
        		p->next->random = p->random->next;
        	p = p->next->next;
        }

        RandomListNode *res = head->next;
        p = head;
        while (p && p->next)
        {
            tmp = p->next;
            p->next = p->next->next;
            p = tmp;
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	RandomListNode *l = new RandomListNode(-1);
	s.copyRandomList(l);

	return 0;
}
