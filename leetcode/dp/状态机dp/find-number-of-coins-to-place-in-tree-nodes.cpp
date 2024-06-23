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
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<ll> res(n);
        vvi graph(n);
        for (auto &e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        function<vi(int, int)> dfs = [&](int x, int p) -> vi {
            vi cur;
            cur.push_back(cost[x]);
            ll ans = 0;
            for (int child : graph[x])
            {
                if (child == p) continue;
                auto t = dfs(child, x);
                cur.insert(cur.end(), t.begin(), t.end());
                if (t.size() > 2) ans = max(ans, res[child]);
            }

            int n = cur.size();
            if (n < 3)
                res[x] = 1;
            else
            {
                sort(cur.begin(), cur.end());
                res[x] = max({ans, (ll)cur[0] * cur[1] * cur[n - 1], (ll)cur[n - 1] * cur[n - 2] * cur[n - 3]});
            }

            if (n <= 3)
                return cur;
            else
                return {cur[0], cur[1], cur[n - 1], cur[n - 2]};
        };
        dfs(0, -1);
        return res;
    }
};