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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *i1 = headA, *i2 = headB;
        bool flag = false;
        while (i1 != i2)
        {
            i1 = i1->next;
            if (!i1) 
            {
                if (flag) return nullptr;
                else flag = true;
                i1 = headB;
            }
            i2 = i2->next;
            if (!i2) i2 = headA;
        }
        return i1;
    }
};