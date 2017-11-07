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
     * @param root: The root of binary tree
     * @return: root of new tree
     */
    TreeNode * cloneTree(TreeNode * root) {
    	if (root == NULL)
    		return NULL;

    	TreeNode *res = new TreeNode(root->val);
    	res->left = cloneTree(root->left);
    	res->right = cloneTree(root->right);
    	return res;
    }
};
