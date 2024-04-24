#include <unordered_map>

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
    unordered_map<long long, int> prefix;
    int target;
    int res = 0;

    void dfs(TreeNode *node, long long sum)
    {   
        if (node == nullptr) return;
        sum += node->val;
        auto r = prefix.find(sum - target);
        if (r != prefix.end())
            res += r->second;
        
        ++prefix[sum];
        dfs(node->left, sum);
        dfs(node->right, sum);
        --prefix[sum];
    }

    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        target = targetSum;
        dfs(root, 0);
        return res;
    }
};