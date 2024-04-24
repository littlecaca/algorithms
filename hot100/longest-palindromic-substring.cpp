#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int first_index = 0;
        int length = 1;
        vector<bool> dp(s.size());
        dp[0] = true;

        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == s[i - 1])
                dp[i] = true;
            else dp[i] = false;

            for (int j = 0; j <= i - 1; ++j)
            {
                if (s[i] == s[j] && dp[j + 1])
                {
                    dp[j] = true;
                    if (length < i - j + 1)
                    {
                        length = i - j + 1;
                        first_index = j;
                    }
                }
                else dp[j] = false;
            }
            dp[i] = true;
        }
        return s.substr(first_index, length);
    }
};
