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
    int numDecodings(string s) {
        unordered_set<string> items;
        REP (i, 1, 26)
            items.insert(to_string(i));
        
        int n = s.size();
        vi dp(n + 1);
        dp[0] = 1;
        REP(i, 0, n - 1)
        {
            if (items.count(s.substr(i, 1)))
                dp[i + 1] += dp[i];
            if (i - 1 >= 0 && items.count(s.substr(i - 1, 2)))
                dp[i + 1] += dp[i - 1];
        }
        return dp[n];
    }
};