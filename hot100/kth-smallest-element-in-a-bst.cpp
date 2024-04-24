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
    TreeNode *res = nullptr;
    int check(TreeNode *cur, int k)
    {
        if  (cur == nullptr)
            return 0;
        int less = check(cur->left, k);
        if (less == -1) return -1;
        if (k == less + 1)
        {
            res = cur;
            return -1;
        }
        int more = check(cur->right, k - less - 1);
        if (more == -1) return -1;

        return 1 + less + more;
    }
    int kthSmallest(TreeNode* root, int k) {
        check(root, k);
        return res->val;
    }
};