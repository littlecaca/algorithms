#include <numeric>
#include <unordered_set>
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
#define INF 0x3f3f3f3f

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
    int deleteString(string s) {
        int n = s.size();
        vvi record(n + 1, vi(n + 1));
        vi dp(n, 1);

        // 预处理
        // 计算s[i:]与s[j:]的最长公共前缀
        _REP(i, n - 1, 0)
        {
            _REP(j, n - 1, i + 1)
            {
                if (s[i] == s[j])
                {
                    record[i][j] = record[i + 1][j + 1] + 1;
                }
            }
        }

        _REP(i, n - 1, 0)
        {
            int right = (n - i) / 2 + i;
            REP(j, i + 1, right)
            {
                if (record[i][j] >= j - i)
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        return dp[0];
    }
};