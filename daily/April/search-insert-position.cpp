#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int t = nums[mid];
            if (target == t)
                return mid;
            if (target > t)
                left = mid + 1;
            if (target < t)
                right = mid - 1;
        }
        return left;
    }
};