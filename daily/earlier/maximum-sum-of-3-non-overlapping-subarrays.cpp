#include <vector>
#include <map>

using namespace std;    


class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // 前缀和
        int length = nums.size();
        vector<int> sum(length);
        sum[0] = nums[0];
        for (int i = 1; i != length; ++i)
        {
            sum[i] = sum[i - 1] + nums[i];
        }

        vector<vector<int>> dp(length, vector<int>(4));
        dp[k - 1][1] = sum[k - 1];
        for (int i = k; i != length; ++i)
        {
            for (int j = 1; j <= 3; ++j)
            {
                dp[i][j] = max(dp[i - k][j - 1] + sum[i] - sum[i - k], dp[i - 1][j]);
            }
        }

        vector<int> ans(3);
        int i = length - 1, j = 3, idx = 2;
        while (j > 0 && i >= k)
        {
            if (dp[i - k][j - 1] + sum[i] - sum[i - k] <= dp[i - 1][j])
            {
                --i;
            }
            else
            {
                ans[idx--] = i - k + 1;
                i -= k;
                --j;
            }
        }
        return ans;
    }
};

