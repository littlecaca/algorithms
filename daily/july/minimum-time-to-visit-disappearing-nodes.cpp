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
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vvpii graph(n);
        
        for (auto &edge : edges)
        {
            auto x = edge[0], y = edge[1], z = edge[2];
            graph[x].push_back({y, z});
            graph[y].push_back({x, z});
        }

        vi dist(n, -1);

        auto dijkstra  = [&]() -> void {
            priority_queue<pii, vector<pii>, greater<pii>> que;
            que.push({0, 0});
            dist[0] = 0;
            while (!que.empty())
            {
                auto [d, node] = que.top();
                que.pop();
                if (d > dist[node]) continue;
                for (auto [next, len] : graph[node])
                {
                    int next_d = len + d;
                    if (disappear[next] <= next_d) continue;

                    if (dist[next] == -1)
                    {
                        dist[next] = next_d;
                        que.push({next_d, next});
                    }
                    else if (chmin(dist[next], next_d))
                        que.push({next_d, next});
                }
            }
        };

        dijkstra();
        return dist;
    }
};