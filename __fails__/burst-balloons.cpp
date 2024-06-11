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
    int maxCoins(vector<int>& nums) {
        /**
         * 经典区间dp
         * 考察思维
         */
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        /**
         * 记忆化搜索 时间复杂度O(n3)
         */
        // vvi memo(n, vi(n, -1));

        // function<int(int, int)> recur = [&](int start, int end) -> int {
        //     if (memo[start][end] != -1) return memo[start][end];
            
        //     if (start + 1 == end)
        //         return 0;
        //     if (start + 2 == end)
        //         return memo[start][end] = nums[start] * nums[start + 1] * nums[end];

        //     int ans = 0;
        //     REP(i, start + 1, end - 1)
        //     {
        //         int cur = recur(start, i) + recur(i, end) + nums[start] * nums[i] * nums[end];
        //         if (cur > ans)
        //             ans = cur;
        //     }
        //     return memo[start][end] = ans;
        // };

        // return recur(0, n - 1);

        /**
         * 递推, 一个正序遍历，一个倒序遍历，即可实现递推
         */
        vvi dp(n, vi(n));
        REP(i, 2, n - 1)
        {
            _REP(j, i - 2, 0)
            {
                int mx = 0;
                REP(k, j + 1, i - 1)
                    mx = max(mx, dp[j][k] + dp[k][i] + nums[j] * nums[k] * nums[i]);
                dp[j][i] = mx;
            }
        }
        return dp[0][n - 1];
    }
};
