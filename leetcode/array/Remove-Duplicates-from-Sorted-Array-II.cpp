#include <vector>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto left = nums.begin(), right = left + 1;

        int count = 0;
        while (right != nums.end())
        {
            if (*left != *right)
            {
                count = 0;
                ++left;
                *left = *right;
            }
            else if (++count == 1)
            {
                ++left;
                *left = *right;
            }
            ++right;
        }
        return left - nums.begin() + 1;
    }
};