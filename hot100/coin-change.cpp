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
    int coinChange(vector<int>& coins, int amount) {
        // 完全背包问题
        #define INF (int)1e7
        vi dp(amount + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = 1; j <= amount; ++j)
            {
                if (j >= coins[i])
                {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        return (dp[amount] == INF) ? -1 : dp[amount];
    }
};