#include <iostream>

#include <vector>

using namespace std;

// 这次使用滚动数组法

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int height = obstacleGrid.size(), width = obstacleGrid[0].size();
        vector<int> ans(width);
        ans[0] = obstacleGrid[0][0] == 1 ? 0 : 1;

        for (int i = 0; i != height; ++i)
        {
            for (int j = 0; j != width; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                    ans[j] = 0;
                
                else if (j - 1 >= 0)
                    ans[j] += ans[j - 1];
            }   
        }
        return ans[width - 1];
    }   
};

