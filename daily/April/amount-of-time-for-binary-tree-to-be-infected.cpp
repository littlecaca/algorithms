#include <functional>

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
 /*
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        int res = 0;
        function<pair<int, bool>(TreeNode *)> backTracking = [&](TreeNode *node) -> pair<int, bool> {
            if (!node) return {0, false};
            
            auto left_dis = backTracking(node->left);
            auto right_dis = backTracking(node->right);
            if (!left_dis.second && !right_dis.second)
            {
                if (node->val == start)
                {
                    res = max({res, left_dis.first, right_dis.first});
                    return {0, true};
                }
                else
                    return {max(left_dis.first, right_dis.first) + 1, false};
            }   
            else if (left_dis.second)
            {
                res = max(res, right_dis.first + left_dis.first + 1);
                return {left_dis.first + 1, true};
            }
            else
            {
                res = max(res, right_dis.first + left_dis.first + 1);
                return {right_dis.first + 1, true};
            }
        };
        backTracking(root);
        return res;
    }
};