#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int cur = 0;
        for (auto n : nums)
        {
            cur += n;
            if (cur > max)
                max = cur;

            if (cur < 0)
                cur = 0;
        }
        return max;
    }
};