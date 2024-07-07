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
    bool check(const string &word, const unordered_set<int> &record)
    {
        if (word[0] == '0') return false;
        int ans = 0;
        for (auto c : word)
            ans = (ans << 1) + (c - '0');
        return record.count(ans);
    }

    int minimumBeautifulSubstrings(string s) {
        if (s.front() == '0') return -1;
        int n = s.size();
        
        vi dp(n + 1, INT_MAX);
        dp[0] = 0;
        unordered_set<int> record;
        int cur = 1;
        int limit = 1 << 16;
        while (cur < limit)
        {
            record.insert(cur);
            cur *= 5;
        }

        REP(i, 0, n - 1)
        {
            REP(j, 0, i)
            {
                if (dp[j] != INT_MAX && check(s.substr(j, i - j + 1), record))
                    dp[i + 1] = min(dp[i + 1], dp[j] + 1);
            }
        }
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};