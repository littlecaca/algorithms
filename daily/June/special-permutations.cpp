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
    constexpr bool check1(int x, int i)
    {
        return x & (1 << i);
    }

    constexpr int use(int x, int i)
    {
        return x | (1 << i);
    }

    constexpr bool check2(int x, int y)
    {
        return x % y == 0 || y % x == 0;
    }

    int specialPerm(vector<int>& nums) {
        /**
         * 状态压缩dp
         */
        constexpr int mod = 1e9 + 7;
        int n = nums.size();
        int m = 1 << n;
        vvi dp(m, vi(n));
        REP(i, 0, n - 1)
            dp[1 << i][i] = 1;

        REP(i, 1, m - 1)
        {
            REP(j, 0, n - 1)
            {
                if (check1(i, j))
                {
                    int tar = i ^ (1 << j);
                 
                    REP(k, 0, n - 1)
                        if (j != k && check2(nums[j], nums[k]))
                            dp[i][j] = (dp[i][j] + dp[tar][k]) % mod;
                }
            }
        }

        int ans = 0;
        for (auto i : dp[m - 1])
            ans = (ans + i) % mod;
        return ans;
    }
};