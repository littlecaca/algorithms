/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast)
        {
            slow = slow->next;
            if (fast->next)
                fast = fast->next->next;
            else
                return false;
                
            if (slow == fast)
                return true;
        }
        return false;
    }
};