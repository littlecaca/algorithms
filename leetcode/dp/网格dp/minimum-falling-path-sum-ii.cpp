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
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vvi dp(n + 1, vi(n));
            
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0) dp[i + 1][j] = 0;
                else dp[i + 1][j] = INT_MAX;
                
                for (int k = 0; k < n; ++k)
                {
                    if (k == j) continue;
                    chmin(dp[i + 1][j], dp[i][k]);
                }
                dp[i + 1][j] += grid[i][j];
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());

    }
};