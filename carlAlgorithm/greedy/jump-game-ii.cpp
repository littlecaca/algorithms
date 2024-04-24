#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int left = 0, right = 0;
        int last = nums.size() - 1;
        while (right < last)
        {
            int temp = right;
            while (left <= right)
            {
                temp = max(temp, nums[left] + left);
                ++left;
            }
            right = temp;
            ++step;
        }
        return step;
    }
};