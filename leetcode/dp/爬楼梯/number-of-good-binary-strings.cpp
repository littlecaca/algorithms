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
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        #define MOD ((int)1e9 + 7)

        // ======================================
        //          超出时间限制 O(n**2)
        //     划分了冗余的状态，导致虽然正确，但
        //     增加了时间复杂度。
        // ======================================
        // vpii dp(maxLength + 1);
        // dp[0] = {1, 1};

        // for (int i = 1; i < maxLength + 1; ++i)
        // {
        //     // 以1结尾
        //     for (int j = oneGroup; i >= j; j += oneGroup)
        //     {
        //         dp[i].first = (dp[i].first + dp[i - j].second) % MOD;
        //     }
        //     // 以0结尾
        //     for (int j = zeroGroup; i >= j; j += zeroGroup)
        //     {
        //         dp[i].second = (dp[i].second + dp[i - j].first) % MOD;
        //     }
        // }

        // ll ans = 0;
        // for (int i = minLength; i <= maxLength; ++i)
        // {
        //     // cout << i << ": " << dp[i].first << ", " << dp[i].second << endl;
        //     ans = (ans + dp[i].first + dp[i].second) % MOD;
        // }
        // return ans;

        // ========================================================
        //       将题目转化为一次只能走onegroup或者zerogroup步
        //   的爬楼梯问题。原来这题只不过是爬楼梯问题换了一种方式表述。
        // ========================================================
        vi dp(maxLength + 1);
        dp[0] = 1;
        ll ans = 0;
        for (int i = 1; i < maxLength + 1; ++i)
        {
            if (i >= oneGroup)
                dp[i] = (dp[i] + dp[i - oneGroup]) % MOD;
            if (i >= zeroGroup)
                dp[i] = (dp[i] + dp[i - zeroGroup]) % MOD;
            if (i >= minLength)
                ans = (ans + dp[i]) % MOD;
        }
        return ans;

    }
};