#include <queue>
#include <functional>
#include <forward_list>
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

typedef vector<pii> Chain;
typedef vector<Chain> Graph;

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        /**
         * 考察树的深度优先遍历
         * 
        */
        int n = edges.size() + 1;
        Graph gra(n);
        for (auto &e : edges)
        {
            gra[e[0]].push_back({e[1], e[2]});
            gra[e[1]].push_back({e[0], e[2]});
        }

        function<int(int, int, int)> dfs = [&](int f, int x, int d) -> int {
            int cur = 0;
            if (d % signalSpeed == 0) ++cur;
            for (auto &neigh : gra[x])
            {
                /**
                 * 因为是一颗树，所以可以仅通过判断不是父节点来避免重复
                */
                if (neigh.first == f) continue;
                cur += dfs(x, neigh.first, d + neigh.second);
            }
            return cur;
        };

        vi res(n);
        REP(i, 0, n - 1)
        {
            int count = 0;
            int ans = 0;
            auto &neighs = gra[i];
            if (neighs.size() == 1) continue;
            for (auto &n : neighs)
            {
                int t = dfs(i, n.first, n.second);
                ans += count * t;
                count += t;
            }
            res[i] = ans;
        }
        return res;
    }
};
