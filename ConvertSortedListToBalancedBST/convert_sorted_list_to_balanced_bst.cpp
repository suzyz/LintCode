#include <iostream>
#include <cstdio>
#include <cstring>
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

  class TreeNode {
  public:
     int val;
      TreeNode *left, *right;
      TreeNode(int val) {
          this->val = val;
          this->left = this->right = NULL;
      }
  };
 


class Solution {
public:
    /*
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode * sortedListToBST(ListNode * head) {
    	if (head == NULL)
    		return NULL;

        int n = 0;
        ListNode *cur = head, *pre;
        while (cur)
        {
        	++n;
        	cur = cur->next;
        }

        int mid = n/2;
        cur = pre = head;
        for (int i = 0; i < mid; ++i)
        {
        	pre = cur;
        	cur = cur->next;
        }
        pre->next = NULL;
        // printf("n:%d mid:%d %d %d\n",n,mid,head->val,cur->val );
        
        TreeNode *res = new TreeNode(cur->val);
        if (n > 1)
        {
        	if (mid)
        		res->left = sortedListToBST(head);
        	if (n - mid - 1)
        		res->right = sortedListToBST(cur->next);        	
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	ListNode *l = new ListNode(1);
	l->next = new ListNode(2);
	l->next->next = new ListNode(3);

	Solution s;
	s.sortedListToBST(l);
	return 0;
}
