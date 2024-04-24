#include <functional>
#include <vector>

using namespace std;


class Solution {
public:
    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> trace(51);
        vector<vector<int>> primes(51);
        vector<vector<int>> tree(nums.size());

        // 求1~50每个数在1~50内的互质数
        for (int i = 1; i <= 50; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                if (gcd(i, j) == 1)
                {
                    primes[i].push_back(j);
                    if (i != j) primes[j].push_back(i);
                }
            }
        }

        // 将edges输入tree
        for (auto &e : edges)
        {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        vector<int> res(nums.size());
        int count = 0;
        function<void(int, int)> dfs = [&](int parent, int cur) {
            int ans = -1, order = -1;
            for (auto t : primes[nums[cur]])
            {
                if (!trace[t].empty())
                {
                    auto &p = trace[t].back();
                    if (p.second > order)
                    {
                        order = p.second;
                        ans = p.first;
                    }
                }
            }
            res[cur] = ans;

            trace[nums[cur]].push_back({cur, count});
            ++count;

            // 缩小规模
            for (int next : tree[cur])
            {
                if (next != parent)
                {
                    dfs(cur, next);
                }
            }
            trace[nums[cur]].pop_back();
            --count;
        };
        
        dfs(-1, 0);
        return res;
    }
};