#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp1(n), dp2(grid[0]);
        for (int i = 1; i != m; ++i)
        {
            for (int j = 0; j != n; ++j)
            {
                int small = __INT_MAX__;
                int tar = grid[i][j];
                for (int k = 0; k != n; ++k)
                {
                    small = min(small, dp2[k] + moveCost[grid[i - 1][k]][j] + tar);
                }
                dp1[j] = small;
            }
            swap(dp2, dp1);
        }
        return *min_element(dp2.begin(), dp2.end());
    }
};