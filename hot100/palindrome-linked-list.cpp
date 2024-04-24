#include <vector>


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
    bool isPalindrome(ListNode* head) {
        std::vector<int> record;
        while (head)
        {
            record.push_back(head->val);
            head = head->next;
        }
        int left = 0, right = record.size() - 1;
        while (left < right)
        {
            if (record[left++] != record[right--])
                return false;
        }
        return true;
    }
};