#include <vector>

using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        exchange(nums, 0, nums.size() - k - 1);
        exchange(nums, nums.size() - k, nums.size() - 1);
        exchange(nums, 0, nums.size() - 1);
    }

    void exchange(vector<int>& nums, int start, int end)
    {
        while (start < end)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            ++start;
            --end;
        }
    }
};