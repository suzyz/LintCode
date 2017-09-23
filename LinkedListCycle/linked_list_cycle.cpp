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
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode * head) {
        if (head == NULL)
            return false;
            
        int i=1;
        ListNode *p = head -> next;
        
        while (p!=NULL) {
            ListNode *q = head;
            for (int j=0; j<i; j++) {
                if (q == p)
                    return true;
                    
                q = q->next;
            }
            
            p = p ->next;
            i++;
        }
        return false;
    }
};
