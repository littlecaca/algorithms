#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        q1.push(root);
        while (!q1.empty())
        {
            int len = q1.size();
            int count = 0;
            int temp = len;
            while (temp--)
            {
                TreeNode* cur = q1.front();
                q1.pop();
                if (cur)
                {
                    count += cur->val;
                    if (cur->left)
                        q1.push(cur->left);
                    if (cur->right)
                        q1.push(cur->right);
                    q1.push(nullptr);
                }
                q2.push(cur);
            }

            while (!q2.empty())
            {
                TreeNode* cur = q2.front();
                q2.pop();
                TreeNode* cur2 = nullptr;
                int local = 0;
                if (cur)
                {
                    local += cur->val;
                    if (!q2.empty())
                    {
                        cur2 = q2.front();
                        q2.pop();
                        if (cur2)
                        {
                            local += cur2->val;
                        }
                    }
                    cur->val = count - local;
                    if (cur2)
                        cur2->val = count - local;
                }
            }
        }
        return root;
    }
};