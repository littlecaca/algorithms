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
    int countGoodStrings(int low, int high, int zero, int one) {
        #define MOD ((int)1e9 + 7)
        vi dp(high + 1);
        dp[0] = 1;
        ll ans = 0;
        for (int i = 1; i <= high; ++i)
        {
            if (i >= one)
                dp[i] += dp[i - one] % MOD;
            if (i >= zero)
                dp[i] += dp[i - zero] % MOD;
            if (i >= low)
                ans = (ans + dp[i] % MOD) % MOD;
        }
        return ans;
    }
};