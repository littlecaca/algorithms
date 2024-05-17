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
    bool isThereAPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) & 1) return false;
        int r = (m + n - 1) / 2 + 1;
        vector<vector<vector<bool>>> dp(2, vector<vector<bool>>(n + 1, vector<bool>(r)));
        int cur = 0, last = 1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                int val = grid[i][j - 1];
                if (i == 0 && j == 1)
                {
                    dp[cur][j][val] = true;
                    continue;;
                }
                auto &left = dp[cur][j - 1];
                auto &up = dp[last][j];
                auto &tar = dp[cur][j];
                for (int k = 0; k < r; ++k)
                {
                    if ((left[k] || up[k]) && k + val < r)
                        tar[k + val] = true;
                    else if (k + val < r)
                        tar[k + val] = false;
                }
            }
            swap(cur, last);
        }
        return dp[last].back()[r - 1];
    }
};