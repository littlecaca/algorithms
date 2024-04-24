#include <vector>
#include <deque>

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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode *> res;
        if (n == 1) return { new TreeNode };
        
        for (int left = 1; left < n; left += 2)
        {
            vector<TreeNode *> leftTree = allPossibleFBT(left);
            vector<TreeNode *> rightTree = allPossibleFBT(n - left - 1);
            for (int i = 0; i < leftTree.size(); ++i)
            {
                for (int j = 0; j < rightTree.size(); ++j)
                {
                    TreeNode *node = new TreeNode;
                    node->left = leftTree[i];
                    node->right =rightTree[j];
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};