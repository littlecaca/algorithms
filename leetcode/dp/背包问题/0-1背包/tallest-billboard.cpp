#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <fstream>
#include <numeric>
#include <iostream>
#include <climits>
#include <forward_list>
#include <functional>

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

# define REP(i,a,b) for(int i = a; i <= b; ++i)
# define _REP(i,a,b) for(int i = a; i >= b; --i)
# define DEBUG(num) cout << "debug: " << num << endl;

template <typename T>
bool chmin(T &a, const T &b)
{
	if (a <= b) return false;
	a = b;
	return true;
}

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int up = accumulate(rods.begin(), rods.end(), 0);

        /**
         * 记忆化搜索
        */
        // vvi memo(n, vi(up + 1, -1));

        // function<int(int, int)> dfs = [&](int i, int k) -> int {
        //     if (i < 0)
        //     {
        //         if (k == 0) return 0;
        //         return INT_MIN;
        //     }
        //     if (memo[i][k] != -1) return memo[i][k];

        //     memo[i][k] = max({dfs(i - 1, k), dfs(i - 1, abs(k - rods[i])) + rods[i], 
        //         dfs(i - 1, k + rods[i]) + rods[i]});
            
        //     return memo[i][k];
        // };

        // return dfs(n - 1, 0) / 2;

        /**
         * 递推
        */
        vvi dp(2, vi(up + 1, INT_MIN));
        int cur = 0, last = 1;
        dp[last][0] = 0;
        for (int rod : rods)
        {
            _REP(i, up, 0)
            {
                dp[cur][i] = max(dp[last][i], dp[last][abs(i - rod)] + rod);
                if (i + rod <= up)
                    dp[cur][i] = max(dp[cur][i], dp[last][i + rod] + rod);
            }
            swap(cur, last);
        }
        return dp[last][0] / 2;
    }
};