#include <utility>

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
    // pair<ListNode *, ListNode *> sort(ListNode *left, ListNode *right)
    // {
    //     int judge = left->val;
    //     ListNode *start = left;
    //     ListNode *end = left;
    //     ListNode *cur = left->next;

    //     while (cur != right)
    //     {
    //         if (cur->val < judge)
    //         {
    //             end->next = cur->next;
    //             cur->next = start;
    //             start = cur;
    //             cur = end->next;
    //         }
    //         else
    //         {
    //             end = cur;
    //             cur = cur->next;
    //         }
    //     }
    //     if (start != left && start->next != left)
    //     {
    //         auto edge = sort(start, left);
    //         start = edge.first;
    //         edge.second->next = left;
    //     }
    //     if (left != end && left->next != end)
    //     {
    //         auto edge = sort(left->next, end->next);
    //         end = edge.second;
    //         left->next = edge.first;
    //     }

    //     return {start, end};
    // }

    pair<ListNode *, ListNode *> sort(ListNode *head1, ListNode *head2)
    {
        ListNode *cur1 = head1, *cur2 = head2;
        ListNode guard;
        ListNode *last = &guard;

        while (cur1 && cur2)
        {
            if (cur1->val < cur2->val)
            {
                last->next = cur1;
                cur1 = cur1->next;
            }
            else
            {
                last->next = cur2;
                cur2 = cur2->next;
            }
            last = last->next;
        }
        if (cur1)
            last->next = cur1;

        else
            last->next = cur2;

        while (last->next)
            last = last->next;
       
        return {guard.next, last};
    }

    ListNode* sortList(ListNode* head) {
        // 快速排序
        // MD对于倒序的最坏情况超时了
        // 还是用归并排序吧
        // 不然希尔排序？
        
        // 自底向上的归并排序
        ListNode guard;
        guard.next = head;

        int length = 0;
        for (ListNode *cur = head; cur != nullptr; cur = cur->next)
            ++length;

        for (int scale = 1; scale < length; scale <<= 1)
        {
            ListNode *last = &guard, *cur = last->next;
            while (cur)
            {
                // 找第一个子链
                ListNode *head1 = cur;
                for (int i = 1; cur && i < scale; ++i)
                    cur = cur->next;
                if (!cur) break;    // 第一个子链都凑不够，直接退出

                ListNode *head2 = cur->next;
                cur->next = nullptr;
                cur = head2;
                
                // 找第二个子链
                for (int i = 1; cur && i < scale; ++i)
                    cur = cur->next;
                
                // 如果还有剩下的，使cur->next为空，并更新cur指向下一个元素
                if (cur)
                {
                    ListNode *temp = cur->next;
                    cur->next = nullptr;
                    cur = temp;
                }

                auto edge = sort(head1, head2);
                // 将排序后的子链连上主链
                last->next = edge.first;
                last = edge.second;
                last->next = cur;
            }
        }

        return guard.next;
    }
};