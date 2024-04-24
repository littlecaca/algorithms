#include <unordered_map>

using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> record;
        Node *root = new Node(0), *last = root;
    
        // first loop
        for (Node *it = head; it != nullptr; it = it->next)
        {
            last->next = new Node(it->val);
            last = last->next;
            record[it] = last;
        }

        Node *cur = root->next;

        // second loop
        for (Node *it = head; it != nullptr; it = it->next, cur = cur->next)
        {
            if (it->random)
                cur->random = record[it->random];
        }

        Node *res = root->next;
        delete root;
        return res;
    }
};