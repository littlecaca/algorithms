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
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        /**
         * 普通的深度优先遍历，连Astar都用不上
         */
        int n = values.size();
        vi visit(n);
        vvpii graph(n);
        for (auto &e : edges)
        {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        int ans = 0;

        function<void(int, int, int)> dfs = [&](int x, int val, int t) -> void {
            if (t > maxTime) return;
            ++visit[x];
            if (visit[x] == 1) 
                val += values[x];
            if (x == 0) ans = max(ans, val);

            for (auto [node, time] : graph[x])
            {
                dfs(node, val, t + time);
            }
            --visit[x];
        };

        dfs(0, 0, 0);
        return ans;
    }
};