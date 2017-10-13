/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode * insertNode(TreeNode * root, TreeNode * node) {
        if (root == NULL)
            return node;
        TreeNode *p = root;
        while (p)
        {
            if (node->val < p->val)
            {
                if (p->left == NULL)
                {
                    p->left = node;
                    break;
                }
                else
                    p = p->left;
            }
            else
            {
                if (p->right == NULL)
                {
                    p->right = node;
                    break;
                }
                else
                    p = p->right;
            }
        }
        
        return root;
    }
};
