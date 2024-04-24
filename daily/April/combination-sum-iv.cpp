#include <vector>
using namespace std;

// 如果求排列数,就是外层for循环遍历背包内层for循环遍历物品。

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int res;
        vector<int> dp(target + 1);
        dp[0] = 1;
        long long temp;
        for (int i = 1; i <= target; ++i)
        {
            for (auto n : nums)
            {
                if (i >= n)
                {
                    if ((temp = (long long)dp[i - n] + dp[i]) <= INT_MAX)
                        dp[i] = temp;
                }
            }
        }
        return dp[target];
    }
};