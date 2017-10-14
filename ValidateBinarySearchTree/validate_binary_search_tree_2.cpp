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
        return is_valid_bst(root,INT_MIN,INT_MAX);
    }
    bool is_valid_bst(TreeNode *root,int min,int max)
    {
        if (root == NULL)
            return true;
        if (root->val < min || root->val > max)
            return false;

        return is_valid_bst(root->left,min,root->val-1) && is_valid_bst(root->right,root->val+1,max);
    }
};
