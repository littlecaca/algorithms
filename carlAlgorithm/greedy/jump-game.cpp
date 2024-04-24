#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left = 0,
            right = 0;
        int last = nums.size() - 1;

        while (left <= right)
        {
            right = max(right, nums[left] + left);
            if (right >= last) return true;
            ++left;
        }

        return false;
    }
};