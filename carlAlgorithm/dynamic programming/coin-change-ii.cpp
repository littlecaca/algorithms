#include <vector>

using namespace std;

// 完全背包问题

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;

        for (int i = 0; i < coins.size(); ++i)
        {
            int value = coins[i];
            for (int j = 0; j <= amount; ++j)
            {
                if (j >= value) dp[j] = dp[j] + dp[j - value];
            }
        }
        
        
        return dp[amount];
    }
};