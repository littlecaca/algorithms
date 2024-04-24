#include <queue>
#include <vector>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/



class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            auto size = que.size();
            res.push_back({});
            while (size--)
            {
                auto cur = que.front();
                que.pop();
                res.back().push_back(cur->val);
                for (auto n : cur.children)
                {
                    if (n) que.push(n);
                }
            }
        }
        return res;
    }
};