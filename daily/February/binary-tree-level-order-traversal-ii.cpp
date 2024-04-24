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
 // */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> que;
        if (root) que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            res.push_back({});
            while (size--)
            {
                auto cur = que.front();
                que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
                res.back().push_back(cur->val);
            }
        }
        return vector<vector<int>>(res.rbegin(), res.rend());
    }
};