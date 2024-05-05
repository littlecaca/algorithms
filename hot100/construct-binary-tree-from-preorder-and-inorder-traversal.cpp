#include <functional>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        function<TreeNode *(int, int, int)> backTracking = [&](int pre_left, int pre_right, int in) -> TreeNode * {
            if (pre_left > pre_right)
                return nullptr;
            int head = preorder[pre_left];
            TreeNode *cur = new TreeNode(head);
            
            int next_in = in;
            while (inorder[next_in] != head)
                ++next_in;
            int next_pre = pre_left + (next_in - in);
            cur->left = backTracking(pre_left + 1, next_pre, in);
            cur->right = backTracking(next_pre + 1, pre_right, next_in + 1);
            return cur;
        };
        return backTracking(0, preorder.size() - 1, 0);
    }
};