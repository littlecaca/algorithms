#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size(), width = grid[0].size();

        vector<int> ans(width);
        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (j == 0)
                    ans[j] += grid[i][j];
                else if (i == 0)
                    ans[j] = grid[i][j] + ans[j - 1];
                else
                    ans[j] = grid[i][j] + min(ans[j], ans[j - 1]);
            }
        }
        return ans[width - 1];
    }
};