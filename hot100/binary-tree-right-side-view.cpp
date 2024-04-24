#include <vector>
#include <queue>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // 中-右-左遍历
        vector<int> res;
        int max_height = 0;
        queue<TreeNode *> que;
        if (root)
            que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            TreeNode *cur;
            while (size--)
            {
                cur = que.front();
                que.pop();
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
            res.push_back(cur->val);
        }
        return res;
    }
};