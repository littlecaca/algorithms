
#include <climits>
#include <functional>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define _REP(i, a, b) for (int i = a; i >= b; --i)
#define debug(num) cout << "debug: " << num << endl
#define print(mess) cout << mess << endl

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a <= b)
        return false;
    a = b;
    return true;
}

class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        constexpr int mod = 1e9 + 7;

        /**
         * 记忆化搜索
         */
        vvi dp(n, vi(401, -1));

        vi req(n, -1);
        for (auto &r : requirements)
            req[r[0]] = r[1];
        

        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (dp[i][j] != -1) return dp[i][j];
            if (i == 0)
            {
                if (j == 0) return 1;
                else return 0;
            }

            dp[i][j] = 0;
            if (req[i - 1] >= 0)
            {
                if (req[i - 1] > j || j - i > req[i - 1])
                    return 0;
                dp[i][j] = dfs(i - 1, req[i - 1]);
            }
            else
            {
                int k = min(i, j);
                REP(q, 0, k)
                {
                    dp[i][j] = (dp[i][j] + dfs(i - 1, j - q)) % mod;
                }
            }

            return dp[i][j];
        };
            
        return dfs(n - 1, req[n - 1]);
    }
};
