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
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    vector<int> searchRange(TreeNode * root, int k1, int k2) {
        vector<int> res;
        search_range(root,k1,k2,res);
        return res;
    }
    void search_range(TreeNode *root,int st,int en,vector<int> &res)
    {
    	if (root == NULL)
    		return;

    	if (root->val < st)
    	{
    		search_range(root->right,st,en,res);
    		return;
    	}
    	if (root->val > en)
    	{
    		search_range(root->left,st,en,res);
    		return;
    	}
    	search_range(root->left,st,en,res);
    	res.push_back(root->val);
    	search_range(root->right,st,en,res);
    }
};
