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
    struct Node
    {
        TreeNode *p;
        int level;
        Node (TreeNode *q,int l)
        {
            p = q;
            level = l;
        }
    };
    vector<vector<int>> levelOrder(TreeNode * root) {
        vector<vector<int>> ans;
        vector<int> empty_vec;
        queue<Node> q;
        if (root)
            q.push(Node(root,0));
        while (!q.empty())
        {
            Node cur = q.front();
            q.pop();

            if (ans.size() <= cur.level)
                ans.push_back(empty_vec);

            ans[cur.level].push_back(cur.p->val);

            if (cur.p->left)
                q.push(Node(cur.p->left,cur.level + 1));
            if (cur.p->right)
                q.push(Node(cur.p->right,cur.level + 1));
        }
        return ans;
    }
};
