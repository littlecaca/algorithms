/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    void reverse(ListNode *start, ListNode *end)
    {
        ListNode *cur = start->next;
        while (cur != end)
        {
            ListNode *temp = cur->next;
            cur->next = start;
            start = cur;
            cur = temp;
        }
        end->next = start;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode *start = new ListNode, *left = head, *right = head;
        ListNode *res = start;
        res->next = head;
        int count = 1;
        while (right)
        {
            if (count++ % k == 0)
            {
                ListNode *temp = right->next;
                reverse(left, right);
                start->next = right;
                start = left;
                right = temp;
                left = right;
            }
            else
                right = right->next;
        }
        start->next = left;
        ListNode *ans = res->next;
        delete res;
        return ans;
    }
};