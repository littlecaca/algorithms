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
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        vi dp(100);
        int n = strs.size();
        int m = strs[0].size();
        REP(i, 0, m - 1)
        {
            int old = 0;
            REP(j, 0, i - 1)
            {
                bool flag = true;
                REP(k, 0, n - 1)
                {
                    if (strs[k][i] < strs[k][j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag) old = max(old, dp[j]);
            }
            dp[i] = old + 1;
            ans = max(ans, dp[i]);
        }
        return m - ans;
    }
};