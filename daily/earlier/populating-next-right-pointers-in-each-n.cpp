


#define NULL 0

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

#include <deque>

using namespace std;

class Solution {
public:
    Node* connect(Node* root) {
        deque<Node *> q1;
        Node *pre = NULL;
        if (root != NULL)
            q1.push_back(root);
        while (!q1.empty())
        {
            size_t len = q1.size();
            while (len--)
            {
                auto cur = q1.front();
                q1.pop_front();
                if (pre != NULL)
                    pre->next = cur;
                if (cur->left)
                    q1.push_back(cur->left);
                if (cur->right)
                    q1.push_back(cur->right);
                pre = cur;
            }
            pre = NULL;
        }
        
        return root;
    }
};