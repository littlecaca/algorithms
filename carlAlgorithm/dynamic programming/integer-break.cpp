#include <vector>

using namespace std;


class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        vector<int> dp(n + 1);
        
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        for (int i = 4; i <= n; ++i)
        {
            int temp = 0;
            int end = i / 2;
            for (int j = 2; j <= end; ++j)
            {
                temp = max(dp[j] * dp[i - j], temp);
            }
            dp[i] = temp;
        }
        return dp[n];
    }
};