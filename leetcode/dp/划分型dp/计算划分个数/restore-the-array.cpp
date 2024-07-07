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
    int numberOfArrays(string s, int k) {
        constexpr int mod = 1e9 + 7;

        int n = s.size();
        vi dp(n + 1);
        string ks = to_string(k);
        int m = ks.size();
        dp[0] = 1;

        REP(i, 1, n)
        {
            int left = max(1, i - m + 1);
            _REP(j, i, left)
            {
                /**
                 * 这里犯了低级的逻辑错误，有点气人
                 * 不能随便把应该嵌套的条件放在一起
                 */
                if (j == i - m + 1)
                {
                    if (s[j - 1] != '0' && s.substr(j - 1, m) <= ks)
                        dp[i] = (dp[i] + dp[j - 1]) % mod;
                }
                else if (s[j - 1] != '0')
                    dp[i] = (dp[i] + dp[j - 1]) % mod;
            }
        }
        return dp.back();
    }
};
