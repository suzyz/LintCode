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
     * @return: True if this Binary tree is Balanced, or false.
     */

	bool is_balanced(TreeNode *root,int &depth)
	{
		if (root == NULL)
		{
			depth = 0;
			return true;
		}

		int left,right;
		if (!is_balanced(root->left,left) || !is_balanced(root->right,right))
			return false;

		depth = 1 + max(left,right);
		return (abs(left-right) < 2);
	}

    bool isBalanced(TreeNode * root) {
        int depth;
        return is_balanced(root,depth);
    }
};
