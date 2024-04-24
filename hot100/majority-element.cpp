#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0, res = 0;

        for (int n : nums)
        {
            if (vote == 0)
                res = n;
            if (n == res)
                ++vote;
            else
                --vote;
        }
        return res;
    }
};