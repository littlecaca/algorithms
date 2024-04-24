#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto left = nums.begin(), right = left;

        while (right != nums.end())
        {
            if (*right != val)
            {
                int temp = *right;
                *right = *left;
                *left = temp;
                ++left;
            }
            ++right;
        }
        return left - nums.begin();
    }
};