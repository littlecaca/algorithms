#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;


template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}

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
    TreeNode *construct(vi &nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2;
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = construct(nums, left, mid - 1);
        cur->right = construct(nums, mid + 1, right);
        return cur;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vi nums;
        stack<TreeNode *> sta;
        TreeNode *cur = root;
        while (cur || !sta.empty())
        {
            while (cur)
            {
                sta.push(cur);
                cur = cur->left;
            }
            cur = sta.top();
            sta.pop();
            nums.push_back(cur->val);
            cur = cur->right;
        }
        return construct(nums, 0, nums.size() - 1);

    }
};