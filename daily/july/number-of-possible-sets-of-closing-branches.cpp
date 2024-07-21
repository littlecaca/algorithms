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
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vvi graph(n, vi(n, INF));
        REP(i, 0, n - 1)
            graph[i][i] = 0;
        for (auto &r : roads)
        {
            graph[r[0]][r[1]] = min(graph[r[0]][r[1]], r[2]);
            graph[r[1]][r[0]] = min(graph[r[1]][r[0]], r[2]);
        }

        auto kruskal = [&](vvi &graph, int status) -> int {
            REP(k, 0, n - 1)
                if (status & (1 << k))
                    REP(i, 0, n - 1)
                        REP(j, 0, n - 1)
                            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            int res = 0;
            REP(i, 0, n - 1)
            {
                if (status & (1 << i))
                    REP(j, i + 1, n - 1)
                    {
                        if (status & (1 << j))
                            res = max(res, graph[i][j]);
                    }
            }
            return res;
        };

        int limit = 1 << n;
        int res = 0;
        REP(i, 0, limit - 1)
        {
            vvi back = graph;
            if (kruskal(back, i) <= maxDistance)
                ++res;
        }
        return res;
    }
};