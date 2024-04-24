#include <vector>

using namespace std;

class Solution {
public:
    void visit(vector<vector<char>> &grid, vector<vector<bool>> &mark, int x, int y)
    {
        if (mark[x][y] || grid[x][y] != '1') return;
        mark[x][y] = true;
        if (x - 1 >= 0) visit(grid, mark, x - 1, y);
        if (x + 1 < grid.size()) visit(grid, mark, x + 1, y);
        if (y - 1 >= 0) visit(grid, mark, x, y - 1);
        if (y + 1 < grid[0].size()) visit(grid, mark, x, y + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int height = grid.size(), width = grid[0].size();
        vector<vector<bool>> mark(height, vector<bool>(width));
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                if (grid[i][j] == '1' && !mark[i][j])
                {
                    ++res;
                    visit(grid, mark, i, j);
                }
            }
        }
        return res;
    }
};