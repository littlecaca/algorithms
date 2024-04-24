#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        if (s.empty())
            return sum;
        int last = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            sum += abs(s[i] - s[last]);
            last = i;
        }
        return sum;
    }
};

