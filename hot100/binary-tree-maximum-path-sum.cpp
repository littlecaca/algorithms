#include <iostream>
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
    int res = 0;
    int dfs(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        res = max({res, node->val + left, node->val + right, node->val + left + right, node->val});
        return max({left, right, 0}) + node->val;
    }
    
    int maxPathSum(TreeNode* root) {
        // 后序遍历
        res = root->val;
        dfs(root);
        return res;
    }
};