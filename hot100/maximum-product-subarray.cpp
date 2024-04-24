#include <vector>

using namespace std;

using ll = long long;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<pair<ll, ll>> dp(nums.size());
        dp[0] = {nums[0], nums[0]};
        for (int i = 1; i < nums.size(); ++i)
        {
            ll t1 = dp[i - 1].first * nums[i];
            ll t2 = dp[i - 1].second * nums[i];
            dp[i].first = max({(long long)nums[i], t1, t2});
            dp[i].second = min({(long long)nums[i], t1, t2});
        }
        
        return max_element(dp.begin(), dp.end())->first;
    }
};