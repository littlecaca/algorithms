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
        int rows = grid.size(), cols = grid[0].size();
        vvvi dp(rows, vvi(cols, vi(cols, INT_MIN)));
        dp[0][0][cols- 1] = grid[0][0] + grid[0][cols - 1];
        for (int k = 1; k < rows; ++k)
        {
            for (int x1 = 0; x1 < cols; ++x1)
            {
                for (int x2 = x1; x2 < cols; ++x2)
                {
                    int res = INT_MIN;
                    static vpii directions = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {-1, -1}, {1, -1}, {0, 1}, {-1, 1}, {1, 1}};

                    for (auto &dir : directions)
                    {
                        int px1 = x1 + dir.first;
                        int px2 = x2 + dir.second;
                        if (px1 >= 0 && px1 < cols && px2 >= 0 && px2 < cols) 
                            res = max(res, dp[k - 1][px1][px2]);
                    }
                    res += grid[k][x1];
                    if (x1 != x2)
                        res += grid[k][x2];
                    dp[k][x1][x2] = res;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < cols; ++i)
        {
            for (int j = i; j < cols; ++j)
            {
                ans = max(ans, dp[rows - 1][i][j]);
            }
        }
        return ans;
    }
};