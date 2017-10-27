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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode * addLists(ListNode * l1, ListNode * l2) {
        int carry = 0;
        ListNode *res = new ListNode(0);
        ListNode *ans = res;
        while (l1 && l2)
        {
            int d = carry + l1->val + l2->val;
            res->next = new ListNode(d);
            carry = d/10;
            l1 = l1->next;
            l2 = l2->next;
            res = res->next;
        }
        while (l1)
        {
            int d = carry + l1->val;
            res->next = new ListNode(d);
            carry = d/10;
            l1 = l1->next;
            res = res->next;
        }
        while (l2)
        {
            int d = carry + l2->val;
            res->next = new ListNode(d);
            carry = d/10;
            l2 = l2->next;
            res = res->next;
        }
        if (carry)
            res->next = new ListNode(carry);
    
        return ans->next;
    }
};
