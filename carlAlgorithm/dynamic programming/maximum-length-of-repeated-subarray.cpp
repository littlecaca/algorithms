#include <vector>

using namespace std;


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dp(nums2.size() + 1);

        int result = 0;
        for (int i = 0; i < nums1.size(); ++i)
        {
            for (int j = nums2.size(); j > 0; --j)
            {
                if (nums1[i] == nums2[j])
                {
                    int temp = dp[j - 1] = dp[j] + 1;
                    result = max(result, temp);
                }
            }
        }
        return result;
    }
};