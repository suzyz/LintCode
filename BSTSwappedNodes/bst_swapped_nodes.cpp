class Solution {
public:
	TreeNode *p = NULL, *q = NULL, *pre = NULL;
    /*
     * @param : the given tree
     * @return: the tree after swapping
     */
    TreeNode * bstSwappedNode(TreeNode * root) {
    	if (root == NULL)
    		return NULL;

    	dfs(root);

    	if (p && q)
    	{
    		int tmp = p->val;
    		p->val = q->val;
    		q->val = tmp;
    	}

    	return root;
    }

    void dfs(TreeNode *root)
    {
    	if (root == NULL)
    		return;

    	dfs(root->left);

    	if (pre != NULL && root->val < pre->val)
    	{
    		if (p == NULL)
    		{
    			p = pre;
    			q = root;
    		}
    		else
    			q = root;
    	}

    	pre = root;
    	dfs(root->right);
    }
};
