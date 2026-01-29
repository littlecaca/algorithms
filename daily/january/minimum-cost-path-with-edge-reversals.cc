#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        /*
        思路：dijkstra单源最短路径算法。
        改进：需要将每一条入边翻转考虑
        */

        // 这里使用静态邻接表来存储图，static adjacency list
        int M = edges.size();
        vector<int> head(n, -1);
        vector<int> adj(2 * M);
        for (int i = 0; i < M; ++i) {
            auto& edge = edges[i];
            adj[2 * i] = head[edge[0]];
            head[edge[0]] = 2 * i;
            adj[2 * i + 1] = head[edge[1]];
            head[edge[1]] = 2 * i + 1;
        }

        vector<int> costs(n, INT_MAX);
        costs[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que;
        que.emplace(0, 0);
    
        auto dijkstra = [&]() -> void {
            while (!que.empty()) {
                auto [len, tar] = que.top();
                que.pop();
                if (costs[tar] < len) {
                    continue;
                }

                // 遍历边节点
                for (int next = head[tar]; next != -1; next = adj[next]) {
                    auto next_idx = next & 1 ? edges[next / 2][0] : edges[next / 2][1];
                    auto next_w = next & 1 ? edges[next / 2][2] * 2 : edges[next / 2][2];
                    if (next_w + len < costs[next_idx]) {
                        costs[next_idx] = next_w + len;
                        que.emplace(next_w + len, next_idx);
                    }
                }
            }
        };
        dijkstra();
        return costs[n - 1] == INT_MAX ? -1 : costs[n - 1];
    }
};
