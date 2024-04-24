#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 1;
        int res = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
                res = max(res, ++count);
            else
                count = 1;
        }
        return res;
    }
};