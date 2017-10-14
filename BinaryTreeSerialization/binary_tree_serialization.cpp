#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

  class TreeNode {
  public:
      int val;
      TreeNode *left, *right;
      TreeNode(int val) {
          this->val = val;
          this->left = this->right = NULL;
     }
  };


class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        string s;
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        else
            return "";

        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();

            if (cur == NULL)
            {
                s += "#";
                continue;
            }

            s += to_string(cur->val) + ",";
            q.push(cur->left);
            q.push(cur->right);
        }
        return s;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        if (data.length() == 0)
            return NULL;

        TreeNode * root = new TreeNode(0);
        int i = 0;
        while (data[i] != ',')
            root->val = 10 * root->val + data[i++] - '0';
        ++i;

        vector<TreeNode *> pre,now;
        pre.push_back(root);

        while (i < data.length())
        {
            for (int j = 0; j < pre.size(); ++j)
            {
                TreeNode *cur = pre[j];

                i = get_val(data,i,&cur->left,now);
                i = get_val(data,i,&cur->right,now);
            }

            pre = now;
            now = vector<TreeNode *>();
        }
        return root;
    }

    int get_val(string &data,int i,TreeNode **p,vector<TreeNode *> &now)
    {
        if (data[i] == '#')
        {
            *p = NULL;
            return i+1;
        }
        int tmp = 0;
        while (data[i] != ',')
            tmp = 10 * tmp + data[i++] - '0';
        
        *p = new TreeNode(tmp);
        now.push_back(*p);

        return i+1;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    Solution sol;
    string s = sol.serialize(root);
    cout << s<< endl;
    TreeNode *head = sol.deserialize(s);

    printf("head:%d\n", head->val);
    if (head->left) 
        printf("left:%d\n", head->left->val);
    if (head->right) 
        printf("right:%d\n", head->right->val);
    return 0;
}
