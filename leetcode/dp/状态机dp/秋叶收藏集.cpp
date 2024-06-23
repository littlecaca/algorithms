#include <climits>
#include <unordered_set>
#include <stack>
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
    int minimumOperations(string leaves) {
        vi dp(3);
        dp[1] = INT_MAX / 2;
        dp[2] = INT_MAX / 2;
        int count = 0;

        for (auto c : leaves)
        {
            if (c == 'r')
            {
                if (count > 0)
                {
                    int t = dp[1];
                    dp[1] = min(dp[0] + 1, dp[1] + 1);
                    if (count > 1)
                        dp[2] = min(t, dp[2]);
                }
            }
            else
            {
                int t1 = dp[0], t2 = dp[1];
                ++dp[0];
                if (count > 0)
                {
                    dp[1] = min(dp[1], t1);
                    if (count > 1)
                        dp[2] = min(dp[2] + 1, t2 + 1);
                }
            }
            ++count;
        }
        return dp[2];
    }
};