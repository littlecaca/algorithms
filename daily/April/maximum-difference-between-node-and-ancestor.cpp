#include <map>

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
    int res = 0;

    void dfs(TreeNode *node, map<int, int> &record)
    {
        if (node == nullptr) return;
        ++record[node->val];
        res = max(record.rbegin()->first - record.begin()->first, res);
        dfs(node->left, record);
        dfs(node->right, record);
        if (--record[node->val] == 0)
            record.erase(node->val);
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        map<int, int> record;
        dfs(root, record);
        return res;
    }
};