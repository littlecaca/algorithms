#include <vector>

using namespace std;


class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        int res = INT_MAX;
        vector<vector<int>> graph(n);
        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> cost(price.size());
        for (auto &trip : trips)
        {
            dfs(trip[0], trip[1], -1, graph, cost, price);
        }
        sum(0, -1, false, graph, cost, 0, res);
        
        return res;
    }

    void dfs(int start, int end, int fa, vector<vector<int>> &graph, vector<int> &cost, vector<int> &price)
    {
        cost[start] += price[start];
        if (start == end)
        {
            return;
        }
        auto neighbors = graph[start];
        for (int i = 0; i != neighbors.size(); ++i)
        {
            if (neighbors[i] != fa)
            {
                dfs(neighbors[i], end, start, graph, cost, price);
            }
        }
    }

    void sum(int start, int fa, bool flag, vector<vector<int>> &graph, vector<int> &cost, int cur, int &res)
    {
        auto neighbors = graph[start];
        if (neighbors.size() == 1)
        {
            if (flag) cur += cost[start];
            else cur += cost[start] / 2;
            res = min(cur, res);
        }

        for (int i = 0; i != neighbors.size(); ++i)
        {
            if (i != fa)
            {
                if (flag)
                    sum(i, start, !flag, graph, cost, cur + cost[start], res);
                else
                {
                    sum(i, start, !flag, graph, cost, cur + cost[start] / 2, res); 
                    sum(i, start, flag, graph, cost, cur + cost[start], res);
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> s{1,2 };
    pair<int, int> sd{1,2 };
    auto [v, d] = sd;
    return 0;
}
