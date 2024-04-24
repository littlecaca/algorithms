    #include <iostream>
    #include <vector>

    using namespace std;


    class Solution {
    public:
        int maximizeSum(vector<int>& nums, int k) {
            int maximum  = 0;
            int res = 0;
            for (int i : nums)
            {
                maximum = max(maximum, i);
            }
            while (k--)
            {
                res += maximum++;
            }
            return res;
        }
    };