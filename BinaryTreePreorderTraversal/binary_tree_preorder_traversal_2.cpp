/* Without recursion. */
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
        int top = 0;
    	TreeNode *stack[10000];
        bool vis[10000];

        if (root)
        {
            stack[++top] = root;
            vis[top] = false;
        }

        while (top)
        {
            TreeNode *cur = stack[top];
            bool v = vis[top];

            if (!v)
            {
                res.push_back(cur->val);
                vis[top] = true;

                if (cur->left)
                {
                     stack[++top] = cur->left;
                     vis[top] = false;
                }    
            }
            else
            {
                --top;
                if (cur->right)
                {
                    stack[++top] = cur->right;
                    vis[top] = false;
                }
            }
        }
        return res;
    }
};
