#include <functional>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <string>

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
    int largestRectangleArea(vector<int>& heights) {
        stack<int> sta;
        int n = heights.size();
        vector<int> left_edge(n);
        vector<int> right_edge(n);

        for (int i = 0; i < n; ++i)
        {
            while (!sta.empty() && heights[i] <= heights[sta.top()])
            {
                right_edge[sta.top()] = i;
                sta.pop();
            }
            if (sta.empty())
                left_edge[i] = -1;
            else
                left_edge[i] = sta.top();
            sta.push(i);
        }

        while (!sta.empty())
        {
            right_edge[sta.top()] = n;
            sta.pop();
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max((right_edge[i] - left_edge[i] - 1) * heights[i], ans);
        return ans;
    }
};