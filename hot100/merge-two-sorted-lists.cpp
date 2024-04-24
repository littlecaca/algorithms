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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *cur1 = list1, *cur2 = list2;
        ListNode *ans = new ListNode, *p = ans;
        while (cur1 && cur2)
        {
            if (cur1->val > cur2->val)
            {
                p->next = cur2;
                p = cur2;
                cur2 = cur2->next;
            }
            else
            {
                p->next = cur1;
                p = cur1;
                cur1 = cur1->next;
            }
        }
        if (cur1)
            p->next = cur1;
        else
            p->next = cur2;
        ListNode *res =  ans->next;
        delete ans;
        return res;

    }
};