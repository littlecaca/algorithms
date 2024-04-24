#include <map>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i != nums.size(); ++i)
            if (i == 0 || nums[i] != nums[i-1])
            {
                size_t k = nums.size() - 1;
                int target = -nums[i];
                for (size_t j = i + 1; j != nums.size(); ++j)
                {
                    // 由于这个条件，对于内层来说j可以一次加多个
                    if (j == i + 1 || nums[j] != nums[j - 1])
                    {
                        // 此时可能有j > k
                        if (j >= k) break;
                        while (j != k && nums[j] + nums[k] > target)
                        {
                            --k;
                        }
                        if (j == k) break;
                        if (nums[j] + nums[k] == target) 
                        {
                            result.push_back({nums[i], nums[j], nums[k]});
                        }
                    }
                }
            }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {-2,0,1,1,2};
    auto result = Solution().threeSum(nums);
    
    return 0;
}
