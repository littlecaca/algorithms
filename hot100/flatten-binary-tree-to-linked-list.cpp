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

    TreeNode *adapt(TreeNode *node)
    {
        TreeNode *left = nullptr, *right = nullptr;
        if (node->left)
            left = adapt(node->left);
        if (node->right)
            right = adapt(node->right);
        if (!left && !right)
            return node;
        if (!right)
        {
            node->right = node->left;
            node->left = nullptr;
            return left;
        }
        else if (!left)
        {
            return right;
        }
        else
        {
            TreeNode *temp = node->right;
            node->right = node->left;
            node->left = nullptr;
            left->right = temp;
            return right;
        }
        return nullptr;
        
    }
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        adapt(root);
    }
};