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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast != nullptr)
        {   
            if (fast->next == nullptr)
                break;
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                
            }
        }
        return nullptr;
    }
};