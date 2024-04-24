#include <vector>

using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int tar = nums[0];
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] >= tar)
            {
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        if (left < nums.size())
            return nums[left];
        return nums[0];
    }
};