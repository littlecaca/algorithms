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

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        #define MOD ((int)1e9 + 7)
        int m = grid.size(), n = grid[0].size();
        vvvi dp(m + 1, vvi(n + 1, vi(k)));
        dp[1][0][0] = 1;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                auto cur = grid[i - 1][j - 1];
                auto &left = dp[i][j - 1];
                auto &up = dp[i - 1][j];
                auto &tar = dp[i][j];
                for (int u = 0; u < k; ++u)
                {
                    auto &temp = tar[(u + cur) % k];
                    temp = ((temp + left[u]) % MOD + up[u]) % MOD;
                }
            }
        }
        return dp.back().back()[0];
    }
};