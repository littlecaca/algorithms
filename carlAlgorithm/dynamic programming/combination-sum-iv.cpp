#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        long long temp;
        for (int i = 1; i <= target; ++i)
        {
            for (int n : nums)
            {
                if (i >= n) 
                {
                    if ((temp = (long long)dp[i] + dp[i - n]) <= INT_MAX)
                        dp[i] = temp;
                }

            }
        }
        return dp[target];
    }
};