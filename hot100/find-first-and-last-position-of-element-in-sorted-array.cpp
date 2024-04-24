#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int> &nums, int target, bool lower)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] == target))
            {
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = binarySearch(nums, target, true);
        int upper;
        if (lower == nums.size() || nums[lower] != target)
            return {-1, -1};
        for (upper = lower + 1; upper < nums.size() && nums[upper] == target; ++upper)
            ;
        return {lower, upper - 1};
    }
};