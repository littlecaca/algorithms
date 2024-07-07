#include <functional>
#include <string>
#include <unordered_set>
#include <numeric>
#include <stack>
#include <iomanip>
#include <sstream>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <cmath>

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
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0, n = nums.size();
        
        vvi dp(n + 1, vi(2001));
        dp[0][1000] = 1;

        REP(i, 1, n)
        {
            int cur = nums[i - 1];
            REP(j, 0, 2000)
            {
                if (j - cur >= 0)
                    dp[i][j] += dp[i - 1][j - cur];
                if (j + cur <= 2000)
                    dp[i][j] += dp[i - 1][j + cur];
            }
        }
        return dp[n][target + 10000];
    }
};