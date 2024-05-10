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
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vvvi dp(2 * n - 1, vvi(n, vi(n, INT_MIN)));
        if (grid[0][0] == -1) return 0;
        dp[0][0][0] = grid[0][0];
        for (int k = 1; k < 2 * n - 1; ++k)
        {
            for (int x1 = max(0, k - n + 1); x1 <= k && x1 < n; ++x1)
            {
                int y1 = k - x1;
                if (grid[x1][y1] == -1)
                    continue;
                for (int x2 = x1; x2 <= k && x2 < n; ++x2)
                {
                    int y2 = k - x2;
                    if (grid[x2][y2] == -1)
                        continue;

                    int res = dp[k - 1][x1][x2];
                    if (x2 > 0)
                        res = max(res, dp[k - 1][x1][x2 - 1]);
                    if (x1 > 0)
                        res = max(res, dp[k - 1][x1 - 1][x2]);
                    if (x1 > 0 && x2 > 0)
                        res = max(res, dp[k - 1][x1 - 1][x2 - 1]);

                    res += grid[x1][y1];
                    if (x1 != x2)
                        res += grid[x2][y2];
                    dp[k][x1][x2] = res;
                }
            }
        }

        return max(dp[2 * n - 2][n - 1][n - 1], 0);
    }
};
