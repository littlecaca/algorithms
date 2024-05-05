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
//  */

//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };

class Solution {
public:
    bool check(TreeNode *node, ll lower, ll upper)
    {
        if (node == nullptr) return true;
        if (node->val < lower || node->val > upper)
            return false;
        return check(node->left, lower, (ll)node->val - 1) && check(node->right, (ll)node->val + 1, upper);
    }

    bool isValidBST(TreeNode* root) {
        
        return check(root, INT_MIN, INT_MAX);
    }
};