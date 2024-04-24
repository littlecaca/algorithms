#include <vector>

using namespace std;


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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> counts(11);
        counts[10] = 0;
        int num = 0;
        DFS(num, counts, root);
        return num;
    }

    void DFS(int &num, vector<int> &counts, TreeNode *cur)
    {
        if (++counts[cur->val] % 2 == 0)
        {
            --counts[10];
        }
        else
        {
            ++counts[10];
        }

        if (cur->left == nullptr && cur->right == nullptr)
        {
            if (counts[10] <= 1)
                ++num;
        }
        else 
        {
            if (cur->left != nullptr)
            {
                DFS(num, counts, cur->left);
            }
            if (cur->right != nullptr)
            {
                DFS(num, counts, cur->right);
            }
        }

        if (--counts[cur->val] % 2 == 0)
        {
            --counts[10];
        }
        else
        {
            ++counts[10];
        }

    }
};