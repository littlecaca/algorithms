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
    ListNode* swapPairs(ListNode* head) {
        ListNode *pre = new ListNode;
        ListNode *ans = pre;
        ans->next = head;
        ListNode *cur = head;
        
        while (cur  && cur->next)
        {
            ListNode *temp = cur->next;
            cur->next = temp->next;
            temp->next = cur;
            pre->next = temp;
            pre = cur;
            cur = cur->next;
        }
        ListNode *res = ans->next;
        delete ans;
        return res;
    }
};