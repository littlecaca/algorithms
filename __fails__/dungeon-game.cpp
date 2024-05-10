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

// ==========================================
//                  dp
// ------------------------------------------
//           时间复杂度：O（n2）
//  本题失败在没有从寻找最优子结构出发思考，而是
// 不自觉地以为是最小路径和。实际上，只要从问题本
// 身出发，可以先从普通地递归思路开始，就能够发现
// 从目的点到起始点地方向更容易解题。
// ==========================================


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vvi dp(m, vi(n));
        dp[m - 1][n - 1] = max(1 - dungeon[m - 1][n - 1], 1);
        for (int i = m - 1; i >= 0; --i)
        {
            if (i < m - 1)
                dp[i][n - 1] = max(dp[i + 1][n - 1] - dungeon[i][n - 1], 1);
            for (int j = n - 2; j >= 0; --j)
            {
                dp[i][j] = dp[i][j + 1];
                if (i < m - 1)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j]);
                dp[i][j] = max(dp[i][j] - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};
