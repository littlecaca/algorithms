#include <vector>
#include <forward_list>
#include <queue>


using namespace std;



class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<bool> visited(n);
        vector<forward_list<pair<int, int>>> graph(n);
        
        vector<int> check(n);
        vector<int> price(n, ~0);

        for (int i = 0; i < n; ++i)
        {
            check[i] = i;
        }

        for (auto &edge : edges)
        {
            graph[edge[0]].push_front({edge[1], edge[2]});
            graph[edge[1]].push_front({edge[0], edge[2]});
        }

        int count = 0;
        queue<int> que;
        

        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                que.push(i);
                while (!que.empty())
                {
                    int cur = que.front();
                    que.pop();
                    visited[cur] = true;

                    for (auto &p : graph[cur])
                    {
                        if (!visited[p.first])
                        {
                            que.push(p.first);
                            check[p.first] = check[cur];
                            price[check[cur]] &= p.second;
                        }
                    }
                }
            }
        }
        
        vector<int> res;
        for (auto &q : query)
        {
            if (q[0] == q[1])
                res.push_back(0);
            
            else if (check[q[0]] != check[q[1]])
                res.push_back(-1);
            else
                res.push_back(price[check[q[0]]]);
        }
        
        return res;
    }
};