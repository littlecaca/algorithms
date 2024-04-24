#include <stack>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.*/


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode *> sta;
        ListNode *root;
        for (auto i = head; i != nullptr; i = i->next)
        {
            while (!sta.empty() && sta.top()->val < i->val)
            {
                delete sta.top();
                sta.pop();
            }
            if (!sta.empty())
            {
                sta.top()->next = i;
            }
            else root = i;
            sta.push(i);
        }
        return root;
    }
};