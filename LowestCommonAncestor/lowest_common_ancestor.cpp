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
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode * lowestCommonAncestor(TreeNode *root,TreeNode *A,TreeNode *B)
    {
        if (root == A || root == B)
            return root;
    
        if (is_ancestor(root->left,A) && is_ancestor(root->left,B))
            return lowestCommonAncestor(root->left,A,B);
        if (is_ancestor(root->right,A) && is_ancestor(root->right,B))
            return lowestCommonAncestor(root->right,A,B);
        return root;
    }
    
    bool is_ancestor(TreeNode *root,TreeNode *cur)
    {
        if (cur == root)
            return true;
        if (root == NULL)
            return false;
    
        if (is_ancestor(root->left,cur) || is_ancestor(root->right,cur))
            return true;
        else
            return false;
    }
};
