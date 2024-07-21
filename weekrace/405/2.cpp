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
    vector<string> validStrings(int n) {
        vector<string> res;
        string trace(n, 0);
        function<void(int)> dfs = [&](int i) -> void {
            if (i == n)
            {
                res.push_back(trace);
                return;
            }
            if (i > 0 && trace[i - 1] == '0')
            {
                trace[i] = '1';
                dfs(i + 1);
            }
            else
            {
                trace[i] = '1';
                dfs(i + 1);
                trace[i] = '0';
                dfs(i + 1);
            }
        };
        dfs(0);
        return res;
    }
};