#include <vector>

using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int res = 0;
        int cur = 0;
        int flag = 1;
        for (auto n : nums)
        {
            if (n <= threshold)
            {
                if (n % 2 ^ flag)
                {
                    flag = !flag;
                    ++cur;
                    continue;
                    
                }
                else if (n % 2 == 0)
                {
                    res = max(res, cur);
                    cur = 1;
                    flag = 0;
                    continue;
                }
            }
            res = max(res, cur);
            cur = 0;
            flag = 1;
        }
        res = max(res, cur);
        return res;
    }
};