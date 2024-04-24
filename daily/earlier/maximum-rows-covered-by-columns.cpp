#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int height = matrix.size(), width = matrix[0].size();

        vector<vector<bool>> dp(numSelect + 1, vector<bool> (height, false));

        fill(dp[0].begin(), dp[0].end(), true);

        for (int i = 0; i < width; ++i)
        {
            for (int j = numSelect; j > 0; --j)
            {
                int x = 0;
                for (int k = 0; k < height; ++k)
                {
                    if (matrix[k][i] == 1 && dp[j - 1][k] == true) ++x;
                    if (x > 0)
                }

            }
        }

        
    }


};