#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(3));

        dp[0][1] = -prices[0];
    
        for (int i = 1; i < prices.size(); ++i)
        {
            dp[i % 2][0] = dp[(i + 1) % 2][1] + prices[i];      // Cooldown
            dp[i % 2][1] = max(dp[(i + 1) % 2][1], dp[(i + 1) % 2][2] - prices[i]); // Buy
            dp[i % 2][2] = max(dp[(i + 1) % 2][2], dp[(i + 1) % 2][0]); // Sell
        }
        return max(dp[(prices.size() + 1) % 2][2], dp[(prices.size() + 1) % 2][0]);
    }
};