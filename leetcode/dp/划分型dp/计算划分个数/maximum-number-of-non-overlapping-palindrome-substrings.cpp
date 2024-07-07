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
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1) return n;
        vector<vector<bool>> dp(n, vector<bool>(n));
        vi record(n + 1);
        REP(i, 0, n - 1)
            dp[i][i] = true;
        
        
        REP(i, 0, n - 1)
        {
            char cur = s[i];
            record[i + 1] = record[i];
            _REP(j, i - 1, 0)
            {
                if (cur == s[j] && (j == i - 1 || dp[i - 1][j + 1]))
                {
                    dp[i][j] = true;
                    if (i - j + 1 >= k)
                    {
                        record[i + 1] = max(record[i + 1], record[j] + 1);
                        break;
                    }
                }
            }
        }
        return record[n];
    }
};