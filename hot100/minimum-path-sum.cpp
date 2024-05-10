#include <bitset>
#include <numeric>
#include <unordered_map>
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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vi dp(n + 1);
        for (int i = 1; i <= n; ++i)
            dp[i] = grid[0][i - 1] + dp[i - 1];
        dp[0] = INT_MAX;
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j - 1];
            }
        }
        return dp.back();
    }
};