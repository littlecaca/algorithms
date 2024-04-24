#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            for (int j = nums.size() - 1; j > i; --j)
            {
                if (nums[j] > nums[i])
                {
                    swap(nums[i], nums[j]);
                    sort(nums.begin() + i + 1, nums.end());
                    goto end;
                }
            }
        }
        reverse(nums.begin(), nums.end());
        end:
            ;
    }
};