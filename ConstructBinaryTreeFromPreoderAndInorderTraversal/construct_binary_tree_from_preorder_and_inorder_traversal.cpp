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
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        if (n == 0)
        	return NULL;

        return construct(preorder,inorder,0,0,n-1);
    }

    TreeNode* construct(vector<int> &preorder, vector<int> &inorder,int idx,int st,int en)
    {
    	int pos = locate(inorder,st,en,preorder[idx]);
    	TreeNode *res = new TreeNode(preorder[idx]);

    	if (pos > st)
    		res->left = construct(preorder,inorder,idx+1,st,pos-1);
    	if (pos < en)
    		res->right = construct(preorder,inorder,idx+pos-st+1,pos+1,en);
    	return res;
    }

    int locate(vector<int> &v,int st,int en,int d)
    {
    	for (int i = st; i <= en ; ++i)
	    	if (v[i] == d)
	    		return i;

	    return en+1;
    }
};
