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

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vi, greater<int>> left_que, right_que;
        int left = 0, right = costs.size() - 1;
        for (; left < candidates; ++left)
            left_que.push(costs[left]);
        for (int i = 0; right >= left && i < candidates; --right, ++i)
        {
            right_que.push(costs[right]);
        }
        ll ans = 0;
        // 简化判断逻辑
        left_que.push(1e5 + 8);
        right_que.push(1e5 + 8);
        
        for (int i = 0; i < k; ++i)
        {
            if (left_que.top() <= right_que.top())
            {
                ans += left_que.top();
                left_que.pop();
                if (left <= right)
                    left_que.push(costs[left++]);
            }
            else
            {
                ans += right_que.top();
                right_que.pop();
                if (left <= right)
                    right_que.push(costs[right--]);
            }
        }
        return ans;
    }
};