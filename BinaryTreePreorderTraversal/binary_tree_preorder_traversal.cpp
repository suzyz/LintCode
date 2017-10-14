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
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
    	vector<int> res;
    	preorder(root,res);
        return res;
    }
    void preorder(TreeNode *root,vector<int> &res)
    {
    	if (root == NULL)
    		return;
    	res.push_back(root->val);

    	preorder(root->left,res);
    	preorder(root->right,res);
    }
};
