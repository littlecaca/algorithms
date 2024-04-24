#include <algorithm>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int numDistinct(string s, string t) {
        if (t.size() > s.size()) return 0;

        vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1));
        fill(dp[0].begin(), dp[0].end(), 1);

        for (int i = 0; i < t.size(); ++i)
        {
            for (int j = 0; j < s.size(); ++j)
            {
                if (t[i] == s[j])
                {
                    dp[i + 1][j + 1] = dp[i][j] + dp[i + 1][j];
                }
                else
                {
                    dp[i + 1][j + 1] = dp[i + 1][j];
                }
            }
        }
        
        return dp[t.size() - 1][s.size() - 1];
    }
};