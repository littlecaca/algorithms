#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long mid = (0 + nums.size()) / 2;
        long long res = 0;
        
        if (k < nums[mid])
        {
            for (int i = mid; i >= 0 && nums[i] > k; --i)
            {
                res += nums[i] - k;
            }
        }
        else if (k > nums[mid])
        {
            for (int i = mid; i < nums.size() && nums[i] < k; ++i)
            {
                res += k - nums[i];
            }
        }
        return res;
    }
};