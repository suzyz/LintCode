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
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
	int get_max(TreeNode *cur)
	{
		if (cur->right != NULL)
			return get_max(cur->right);

		return cur->val;
	}

    TreeNode * removeNode(TreeNode * root, int value) {
        if (root == NULL)
        	return NULL;

        if (root->val == value)
        {
        	if (root->left == NULL)
        		return root->right;
        	if (root->right == NULL)
        		return root->left;

        	int pre = get_max(root->left);
        	root->val = pre;
            root->left = removeNode(root->left,pre);
        }
        else
        {
	        if (root->val < value)
	        	root->right = removeNode(root->right,value);
	        else
	        	root->left = removeNode(root->left,value);
        }
        return root;
    }
};
