// #include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int count = 0, i;
        for (i = 0; i < nums.size(); i += 2)
        {
            while (i + 1 != nums.size() && nums[i] == nums[i + 1])
            {
                ++count;
                ++i;
            }
        }

        if (i - 1 == nums.size())
            ++count;
        return count;
    }
};