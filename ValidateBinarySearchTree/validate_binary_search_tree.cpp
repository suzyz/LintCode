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
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        if (root == NULL)
            return true;
        if (!is_smaller(root->left,root->val))
            return false;
        if (!is_greater(root->right,root->val))
            return false;
        if (!isValidBST(root->left) || !isValidBST(root->right))
            return false;
        return true;
    }
    bool is_greater(TreeNode *cur,int v)
    {
        if (cur == NULL)
            return true;
        if (cur->val <= v)
            return false;
        return is_greater(cur->left,v) && is_greater(cur->right,v);
    }
    bool is_smaller(TreeNode *cur,int v)
    {
        if (cur == NULL)
            return true;
        if (cur->val >= v)
            return false;
        return is_smaller(cur->left,v) && is_smaller(cur->right,v);
    }
};
