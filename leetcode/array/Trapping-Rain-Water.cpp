#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = height[left], right_max = height[right];
        int count = 0;
        while (left < right)
        {
            if (left_max < right_max)
            {
                ++left;
                while (height[left] < left_max)
                {
                    count += left_max - height[left];
                    ++left;
                }
                left_max = height[left];
            }
            else 
            {
                --right;
                while (height[right] < right_max)
                {
                    count += right_max - height[right];
                    --right;
                }
                right_max = height[right];
            }
        }
        return count;
    }
};