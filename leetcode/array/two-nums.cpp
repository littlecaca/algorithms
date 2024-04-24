#include <vector>
#include <unordered_map>

using namespace std;

// 排列组合问题，用映射结构降低复杂度

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i != nums.size(); ++i)
        {
            auto another = m.find(target - nums[i]);
            if (another != m.end())
            {
                return {i, (*another).second};
            }
            else
            {
                m[nums[i]] = i;
            }
        }
        return {};
    }
};