#include <vector>

using namespace std;


class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        vector<int> record(82);
        for (auto &num : nums)
        {
            int t = num, cur = 0;
            while (t > 0)
            {
                cur += t % 10;
                t /= 10;
            }
            
            int &target = record[cur];
            if (!target)
            {
                target = num;
            }
            else
            {
                ans = max(ans, num + target);
                target = max(num, target);
            }
        }
        return ans;
    }
};