#include <climits>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;


template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode;
        ListNode *cur = head;
        int remain = 0;
        while (remain > 0 || l1 || l2)
        {
            if (l1)
            {
                remain += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                remain += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(remain % 10);
            cur = cur->next;
            remain /= 10;
        }
        auto temp = head->next;
        delete head;
        return temp;
    }
};