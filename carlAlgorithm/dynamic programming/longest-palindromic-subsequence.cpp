#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        for (int i = 0; i < s.size(); ++i)
            dp[i][i] = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i - 1][j + 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i][j + 1], dp[i - 1][j]);
                }
            }
        }
        return dp[s.size() - 1][0];
    }
};