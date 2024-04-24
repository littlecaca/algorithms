#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        sum /= 2;

        vector<int> dp(sum + 1);
        for (int i : nums)
        {
            for (int j = sum; j > 0; --j)
            {
                if (j >= i) dp[j] = max(dp[j - i] + i, dp[j]);
            }
        }
        if (dp[sum] == sum) return true;
        return false;
        
    }
};