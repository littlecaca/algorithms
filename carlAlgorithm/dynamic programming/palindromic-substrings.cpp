#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int countSubstrings(string s) {
        vector<bool> dp(s.size(), true);

        int result = s.size();

        for (int i = 1; i < s.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (s[i] == s[j] && dp[j + 1])
                {
                    ++result;
                    dp[j] = true;
                }
                else
                    dp[j] = false;
            }
        }

        return result;
    }
};