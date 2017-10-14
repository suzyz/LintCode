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
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        vector<vector<int>> ans;
        dfs(root,0,ans);
        return ans;
    }
    void dfs(TreeNode * root, int level,vector<vector<int>> &ans)
    {
    	if (root == NULL)
    		return;
    	if (ans.size() <= level)
    	{
    		vector<int> tmp;
    		ans.push_back(tmp);
    	}
    	ans[level].push_back(root->val);
    	dfs(root->left,level+1,ans);
    	dfs(root->right,level+1,ans);
    }
};
