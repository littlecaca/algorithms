#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cur = 0;
        for (auto n : nums)
        {
            cur ^= n;
        }
        return cur;
    }
};