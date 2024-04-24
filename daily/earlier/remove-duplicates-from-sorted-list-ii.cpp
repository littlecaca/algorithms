#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre = nullptr, *tmp = nullptr, *cur;
        bool flag = true;
        for (cur = head; cur != nullptr; tmp = cur, cur = cur->next)
        {
            if (tmp != nullptr)
            {
                if (tmp->val == cur->val)
                    flag = false;
                else
                {
                    if (flag)
                    {
                        if (pre == nullptr)
                        {
                            pre = tmp;
                            head = pre;
                        }
                        else
                        {
                            pre->next = tmp;
                            pre = pre->next;
                        }
                        pre->next = nullptr;
                    }
                    flag = true;
                }
            }
        }
        if (tmp && flag)
        {
            if (pre)
                pre->next = tmp;
            else
            {
                pre = tmp;
                head = pre;
            }
        }
        if (pre) return head;
        return nullptr;
    }
};