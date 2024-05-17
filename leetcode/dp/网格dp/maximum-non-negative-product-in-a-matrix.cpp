#include <map>
#include <functional>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <limits.h>

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
    int maxProductPath(vector<vector<int>>& grid) {
        #define MOD ((int)1e9 + 7)
        int m = grid.size(), n = grid[0].size();

        vector<pair<ll, ll>> dp(n);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0)
                {
                    dp[j].first = dp[j].second = grid[i][j];
                    continue;
                }
                auto tar = grid[i][j];
                ll mx = LLONG_MIN, mn = LLONG_MAX;
                if (i > 0)
                {
                    mx = max(tar * dp[j].first, tar * dp[j].second);
                    mn = min(tar * dp[j].first, tar * dp[j].second);
                }
                if (j > 0)
                {
                    mx = max({mx, tar * dp[j - 1].first, tar * dp[j - 1].second});
                    mn = min({mn, tar * dp[j - 1].first, tar * dp[j - 1].second});
                }
                dp[j].first = mx;
                dp[j].second = mn;
            }
        }

        auto ans = max(dp.back().first, dp.back().second);
        return ans >= 0 ? ans % MOD : -1;
    }
};