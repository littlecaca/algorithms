#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = nums.size() - 1;
        int cur = 1;
        sort(nums.begin(), nums.end());
        for (int left = 0, right = 1; right < nums.size();)
        {
            if (nums[right] - nums[left] < nums.size())
            {
                if (nums[right] != nums[right - 1])
                    ++cur;
                res = min(res, (int)nums.size() - cur);
                ++right;
            }
            else
            {
                if (nums[left] != nums[left + 1])
                    --cur;
                ++left;
            }
        }
        return res;
    }
};