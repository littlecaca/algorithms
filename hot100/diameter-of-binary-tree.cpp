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
    int res = 0;
    int longest(TreeNode *root)
    {
        int left = 0, right = 0;
        if (root->left)
            left = 1 + longest(root->left);
        if (root->right)
            right = 1 + longest(root->right);
        res = max(res, left + right);
        return max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        longest(root);
        return res;
    }
};