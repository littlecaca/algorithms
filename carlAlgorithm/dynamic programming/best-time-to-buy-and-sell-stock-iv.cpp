#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(2 * k + 1));

        for (int i = 1; i < 2 * k; i += 2)
        {
            dp[0][i] = -prices[0];
        }
        
        for (int i = 1; i < prices.size(); ++i)
        {
            int p = -prices[i];
            for (int j = 1; j <= 2 * k; ++j)
            {
                dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[(i + 1) % 2][j - 1] + p);
                p = -p;
            }
        }

        return dp[(prices.size() + 1) % 2][2 * k];
    }
};