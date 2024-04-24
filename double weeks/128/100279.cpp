#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}

// ==========================================
//      使用优先级队列优化的dijkstra算法
//          （经典模板-熟练掌握）
//         打卡：x
// ==========================================


class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {
        vvpii grap(n);
        for (auto &edge : edges)
        {
            grap[edge[0]].push_back({edge[1], edge[2]});
            grap[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vi ans(n, -1);
        vi dis(n, INT_MAX);

        priority_queue<pii, vpii, greater<pii>> pq;

        pq.push({0, 0});
        dis[0] = 0;

        while (!pq.empty())
        {
            auto tar = pq.top();
            pq.pop();
            auto u = tar.first, v = tar.second;
            if (u > dis[v])
                continue;

            if (u < disappear[v])
            {
                ans[v] = u;
                for (auto &t : grap[v])
                    if (chmin(dis[t.first], u + t.second))
                        pq.push({dis[t.first], t.first});
            }
        }
        return ans;
    }
};