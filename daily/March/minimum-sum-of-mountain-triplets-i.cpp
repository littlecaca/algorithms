#include <vector>

using namespace std;


class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> record(nums.size());
        int ans = INT_MAX;
        int minimum = INT_MAX;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > minimum)
                record[i] = minimum;
            else
                minimum = nums[i];
        }

        minimum = INT_MAX;

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (nums[i] > minimum)
            {
                if (record[i] != 0)
                    ans = min(ans, record[i] + nums[i] + minimum);
            }
            else
                minimum = nums[i];
        }

        return ans == INT_MAX ? -1 : ans;;

    }
};