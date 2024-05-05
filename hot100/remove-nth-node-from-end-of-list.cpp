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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *forward = head, *after = head;
        while (n--)
            forward = forward->next;
        if (forward == nullptr)
        {
            auto temp = head->next;
            delete head;
            return temp;
        }
        forward = forward->next;
        while (forward != nullptr)
        {
            after = after->next;
            forward = forward->next;
        }
        auto temp = after->next;
        after->next = after->next->next;
        delete temp;
        
        return head;
    }
};