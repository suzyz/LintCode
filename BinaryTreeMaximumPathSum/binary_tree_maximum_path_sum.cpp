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
     * @return: An integer
     */
    int maxPathSum(TreeNode * root) {
    	if (root == NULL)
    		return 0;

    	unordered_map<TreeNode *,int> l,r;
    	l[NULL] = r[NULL] = 0;
    	int ans = INT_MIN;
    	calc(root,l,r,ans);
    	return ans;
    }

    void calc(TreeNode *cur,unordered_map<TreeNode *,int> &l,unordered_map<TreeNode *,int> &r,int &ans)
    {
    	if (cur == NULL)
    		return;

    	calc(cur->left,l,r,ans);
    	calc(cur->right,l,r,ans);

  		l[cur] = cur->left == NULL ? 0 : max(0, max(l[cur->left],r[cur->left]) + cur->left->val);
  		r[cur] = cur->right == NULL ? 0 : max(0, max(l[cur->right],r[cur->right]) + cur->right->val);

        ans = max(ans,l[cur] + r[cur] + cur->val);
    }
};
