#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findPivot(vector<int> &nums)
    {
        int left = 0, right = nums.size();
        int tar = nums[0];
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] >= tar)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }


    int search(vector<int>& nums, int target) {
        int edge = findPivot(nums);
        int left = 0, right = edge;
        if (target < nums[0])
        {
            left = edge;
            right = nums.size();
        }
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                right = mid;
            else
                left = mid + 1;
        }
        return -1;
    }
};