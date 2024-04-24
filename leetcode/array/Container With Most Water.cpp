#include <algorithm>
#include <vector>

using namespace std;

// 双指针问题

class Solution {
public:
    int maxArea(vector<int>& height) {
        size_t max = 0, l = 0, r = height.size() - 1;
        while (l < r)
        {
            size_t area = min(height[l], height[r]) * (r - l);
            max = area > max ? area : max;
            if (height[l] < height[r])
            {
                ++l;
            }
            else
            {
                --r;
            }
        }
        return max;
    }
};
