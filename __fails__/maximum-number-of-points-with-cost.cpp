#include <map>
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

// =================================================
//      dp优化----找数学规律，同时考虑一行的状态转移
// =================================================


class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();

        vector<vector<ll>> dp(2, vector<ll>(n));
        int cur = 0, last = 1;
        for (int i = 0; i < m; ++i)
        {
            ll left = LLONG_MIN;
            ll right = LLONG_MIN;
            for (int j = 0; j < n; ++j)
            {
                left = max(left, dp[last][j] + j);
                dp[cur][j] = left + points[i][j] - j;
            }
            for (int j = n - 1; j >= 0; --j)
            {
                right = max(right, dp[last][j] - j);
                dp[cur][j] = max(dp[cur][j], right + points[i][j] + j);
            }
            swap(cur, last);
        }
        return *max_element(dp[last].begin(), dp[last].end());
    }
};