#include <vector>
#include <numeric>

using namespace std;


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // vector<vector<int>> dp(2, vector<int>(2001));
        // int cur = 0, next = 1;
        // dp[cur][1000] = 1;
        // for (int i : nums)
        // {
        //     for (int j = 2000; j >= 0; --j)
        //     {
        //         dp[next][j] = 0;
        //         if (j - i >= 0)
        //             dp[next][j] += dp[cur][j - i];
        //         if (j + i <= 2000)
        //             dp[next][j] += dp[cur][j + i]; 
        //     }
        //     swap(cur, next);
        // }
        // return dp[cur][target + 1000];

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;
        if ((target + sum) % 2 != 0) return 0;
        int left = (target + sum) / 2;
        
        vector<int> dp(left + 1);
        dp[0] = 1;
        for (int i : nums)
        {
            for (int j = left; j - i >= 0; --j)
            {
                dp[j] += dp[j - i];
            }
        }
        return dp[left];
    }
};