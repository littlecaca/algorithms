#include <vector>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int res = 1;

        // 增
        int cur = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                ++cur;
                res = max(res, cur);
            }
            else
                cur = 1;
        }

        // 减
        cur = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                ++cur;
                res = max(res, cur);
            }
            else
                cur = 1;
        }
        return res;
    }
};