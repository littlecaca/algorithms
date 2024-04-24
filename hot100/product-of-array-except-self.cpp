#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int sum = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum *= nums[i];
            ans[i] = sum;
        }

        sum = 1;
        for (int i = nums.size() - 1; i > 0; --i)
        {
            ans[i] = ans[i - 1] * sum;
            sum *= nums[i];
        }
        ans[0] = sum;
        return ans;
    }
};