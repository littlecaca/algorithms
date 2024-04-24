#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<TreeNode *> sta;
        deque<TreeNode *> record;
        int flag = 0;
        TreeNode *temp = root;
        TreeNode *pre = nullptr;

        while (temp != nullptr || !sta.empty())
        {
            if (temp != nullptr)
            {
                sta.push_back(temp);
                temp = temp->left;
            }
            else
            {
                auto cur = sta.back();
                if (pre == cur->right || !cur->right)
                {
                    if (cur == p || cur == q)
                    {
                        if (++flag > 1)
                        {
                            break;
                        }
                        else
                        {
                            record = sta;
                        }
                    }
                    sta.pop_back();
                    pre = cur;
                }
                else
                {
                    temp = cur->right;
                }
            }
        }
        
        int i;
        for (i = 0; i < sta.size(); ++i)
        {
            if (sta[i] != record[i])
            {
                break;
            }
        }
        return sta[i - 1];
    }
};