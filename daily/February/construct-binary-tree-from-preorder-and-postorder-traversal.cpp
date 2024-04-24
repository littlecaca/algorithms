#include <functional>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.*/
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        function<TreeNode *(int, int)> backTracking = [&](int x, int y) -> TreeNode *
        {
            if (x > y) return nullptr;
            TreeNode *cur = new TreeNode(preorder[x]);
            int m = x + 1, n = y - 1;
            while (m <= n && preorder[x] != postorder[y])
            {
                ++m;
            }
            cur->left = backTracking(x + 1, m - 1);
            cur->right = backTracking(m, n);
            return cur;
        };

        return backTracking(0, postorder.size() - 1);
    }
};