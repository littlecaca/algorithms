#include <string>

using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int res = 0, zeros = 0, ones = 0;
        bool  flag;
        for (char c : s)
        {
            if (c == '0')
            {
                if (!flag)
                    zeros = 0;
                flag = true;
                ++zeros;
                ones = 0;
            }
            if (c == '1')
            {
                flag = false;
                ++ones;
                if (ones > res && ones <= zeros)
                {
                    res = max(ones, res);
                }
                
            }
        }
        return res * 2;
    }
};