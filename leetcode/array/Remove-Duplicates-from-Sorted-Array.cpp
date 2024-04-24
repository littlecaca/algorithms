#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto left = nums.begin(), right = left;
        while (right != nums.end())
        {
            if (*left != *right)
            {
                ++left;
                int temp = *right;
                *right = *left;
                *left = temp;
            }
          
            ++right;
        }
        return left - nums.begin() + 1;
    }
};