#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    vector<pair<int, int>> ways = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));

        queue<pair<int, int>> que;
        int time = -1;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 2) que.push({i, j});
            }
        }

        while (!que.empty())
        {
            int count = que.size();
            while (count--)
            {
                auto node = que.front();
                que.pop();
                for (auto &way : ways)
                {
                    int x = node.first + way.first;
                    int y = node.second + way.second;
                    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
                        grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        que.push({x, y});
                    }
                }
            }
            ++time;
        }

        for (auto &line : grid)
        {
            for (auto &cell : line)
            {
                if (cell == 1) return -1;
            }
        }
        
        return max(time, 0);
    }
};