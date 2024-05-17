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
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<bool>>> dp(m + 1, vector<vector<bool>>(n + 1, vector<bool>(101)));
        dp[1][0][0] = true;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                int cur = -1;
                if (grid[i - 1][j - 1] == '(')
                    cur = 1;

                auto &left = dp[i][j - 1];
                auto &up = dp[i - 1][j];
                auto &tar = dp[i][j];
                for (int k = 0; k < 101; ++k)
                {
                    if (left[k] && k + cur >= 0 && k + cur < 101)
                    {
                        tar[k + cur] = true;
                    }
                    if (up[k] && k + cur >= 0 && k + cur < 101)
                    {
                        tar[k + cur] = true;
                    }
                }
            }
        }
        return dp.back().back()[0];

    }
};