#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n));
        grid[m - 1][n - 1] = 1;
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                int temp = 0;
                if (i + 1 != m)
                {
                    temp += grid[i + 1][j];
                }
                if (j + 1 != n)
                {
                    temp += grid[i][j + 1];
                }
                grid[i][j] += temp;
            }
        }
        return grid[0][0];
    }
};