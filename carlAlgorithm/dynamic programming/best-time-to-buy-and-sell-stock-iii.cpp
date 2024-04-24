#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(vector<int>(5)));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for (int i = 1; i < dp.size(); ++i)
        {
            int p = prices[i];
            dp[i][0] = *max_element(dp[i - 1].begin(), dp[i - 1].end());
            dp[i][1] = max(dp[i - 1][1], -p);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + p);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - p);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + p);
        }
        return dp[len - 1][4];
    }
};