#include <vector>

using namespace std;

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
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode guard;
        ListNode *pseudoHead = &guard;
        while (head1 && head2)
        {
            if (head1->val < head2->val)
            {
                pseudoHead->next = head1;
                head1 = head1->next;
            }
            else
            {
                pseudoHead->next = head2;
                head2 = head2->next;
            }
            pseudoHead = pseudoHead->next;
        }
        if (head1)
            pseudoHead->next = head1;
        else
            pseudoHead->next = head2;
        return guard.next;
    }

    ListNode *backTracking(vector<ListNode *> &lists, int start, int end)
    {
        ListNode *head1, *head2;
        if (end - start > 2)
        {
            head1 = backTracking(lists, start, start + (end - start) / 2 + 1);
            head2 = backTracking(lists, start + (end - start) / 2 + 1, end);
        }
        else if (end - start == 2)
        {
            head1 = lists[start];
            head2 = lists[start + 1];
        }
        else if (end - start == 1)
            return lists[start];
        else
            return nullptr;
        
        return merge(head1, head2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return backTracking(lists, 0, lists.size());
    }
};