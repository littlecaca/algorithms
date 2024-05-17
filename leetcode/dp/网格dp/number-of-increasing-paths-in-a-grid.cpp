#include <map>
#include <functional>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;

template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}


class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        // 拓扑排序 + 广度优先遍历
        #define MOD ((int)1e9 + 7)

        int m = grid.size(), n = grid[0].size();
        vvi degree(m, vi(n));
        vvi dp(m, vi(n, 1));

        static const vpii ways = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        queue<pii> que;
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                bool flag = true;
                for (auto &way : ways)
                {
                    int nx = i + way.first, ny = j + way.second;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > grid[i][j])
                    {
                        ++degree[i][j];
                        flag = false;
                    }
                }
                if (flag) que.push({i, j});
            }
        }

        int ans = 0;
        int length = 0;

        while (!que.empty())
        {
            ++length;
            int size = que.size();
            while (size--)
            {
                auto node = que.front();
                que.pop();
                auto cur = dp[node.first][node.second];
                ans = (ans + cur) % MOD;
                
                for (auto &way : ways)
                {
                    int nx = node.first + way.first, ny = node.second + way.second;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] < grid[node.first][node.second])
                    {
                        dp[nx][ny] = (dp[nx][ny] + cur) % MOD;
                        if (--degree[nx][ny] == 0) que.push({nx, ny});
                    }
                }
            }
        }
        return ans;
    }
};