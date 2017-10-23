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
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
       	vector<int> res;
       	inorder_traversal(root,res);
       	return res;
    }
    void inorder_traversal(TreeNode *root, vector<int> &res)
    {
    	if (root == NULL)
    		return;
    	inorder_traversal(root->left,res);
    	res.push_back(root->val);
    	inorder_traversal(root->right,res);
    }
};
