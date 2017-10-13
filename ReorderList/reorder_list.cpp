#include <iostream>
#include <cstdio>
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
     * @return: nothing
     */
    ListNode* reverse_list(ListNode * head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *p = head, *q = head->next, *tmp;
        while (p && q)
        {
            tmp = q->next;
            q->next = p;

            p = q;
            q = tmp;
        }
        head->next = NULL;
        return p;
    }
    void reorderList(ListNode * head) {
        if (head == NULL)
            return;

        ListNode *fast = head,*slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *latter = slow->next;
        slow->next = NULL;

        latter = reverse_list(latter);

        fast = head;
        ListNode *tmp1,*tmp2;
        while (fast && latter)
        {
            tmp1 = fast->next;
            fast->next = latter;
            tmp2 = latter->next;
            fast = latter->next = tmp1;
            latter = tmp2;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    l->next->next->next->next = new ListNode(5);

    s.reorderList(l);

    return 0;
}
