#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto get_width = [](int num) -> int {
            int res = num < 0 ? 1 : 0;
            num = abs(num);
            while (num > 0)
            {
                ++res;
                num /= 10;
            }
            return res;
        };
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            int tar = 1;
            for (int j = 0; j < m; ++j)
            {
                tar = max(get_width(grid[j][i]), tar);
            }
            ans[i] = tar;
        }
        return ans;
    }
};