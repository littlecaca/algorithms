#include <queue>
#include <algorithm>
#include <vector>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> que;
        if (root) que.push(root);
        int level = 0;
        while (!que.empty())
        {
            auto size = que.size();
            res.push_back({});
            while (size--)
            {
                auto cur = que.front();
                que.pop();
                res.back().push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            if (level++ % 2) reverse(res.back().begin(), res.back().end());
        }
        return res;
    }
};