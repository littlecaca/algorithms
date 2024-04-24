#include <vector>

using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 10001);
        dp[0] = 0;
        for (int value : coins)
        {
            for (int i = 1; i <= amount; ++i)
            {
                if (i >= value) dp[i] = min(dp[i], dp[i - value] + 1);
            }
        }
        return dp[amount] == 10001 ? -1 : dp[amount];
    }
};