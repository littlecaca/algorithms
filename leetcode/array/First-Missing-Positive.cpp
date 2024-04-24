#include <cmath>
#include <vector>

using namespace std;

// 用正负号来标记是否有值

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (auto &n : nums)
        {
            if (n <= 0)
            {
                n = nums.size() + 1;
            }
        }
        for (auto &n : nums)
        {
            if (abs(n) <= nums.size())
            {
                // 要处理散列冲突
                int &t = nums[abs(n) - 1];
                if (t > 0) t = -t; 
            }
        }
        for (size_t i = 0; i != nums.size(); ++i)
        {
            if (nums[i] > 0)
                return i + 1;
        }
        return nums.size() + 1;
    }
};