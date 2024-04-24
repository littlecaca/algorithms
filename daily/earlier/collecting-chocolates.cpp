#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long res = accumulate(nums.begin(), nums.end(), 0LL),
                  cur = res;
        int len = nums.size();
        vector<int> minnums(nums);
        for (int i = 1; i != len; ++i)
        {
            for (int j = 0; j != len; ++j)
            {
                int new_value = nums[(j + i) % len];
                if (new_value < minnums[j])
                {
                    cur -= minnums[j] - new_value;
                    minnums[j] = new_value;
                }
            }
            cur += x;
            res = min(res, cur);
        }
        return res;
    }
};