#include <vector>
#include <iostream>
#include <string>

using string = std::string;

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        long long sum = n;
        for (int i = 1; i < 64; i += 2)
            if (sum >> i & 1)
                sum += 2 * (1 << i);
        string res;
        while (sum > 0)
        {
            if (sum & 1)
                res.push_back('1');
            else
                res.push_back('0');
            sum >>= 1;
        }
        return string(res.rbegin(), res.rend());
    }
};
