#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 双指针逼近目标值

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        int closest = abs(result - target);
        
        for (size_t first = 0; first != nums.size(); ++first)
        {
            if (first != 0 && nums[first] == nums[first - 1])
                continue;

            size_t third = nums.size() - 1;
            
            for (size_t second = first + 1; second < third; )
            {
                int sum = nums[first] + nums[second] + nums[third];
                int diff = abs(sum - target);
                if (diff < closest)
                {
                    closest = diff;
                    result = sum;
                }
                else {
                    if (sum > target)
                        --third;
                    else
                        ++second;
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums {-1,2,1,-4};
    Solution().threeSumClosest(nums, 1);
    return 0;
}
