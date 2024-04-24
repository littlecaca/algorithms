#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i)
        {
            for (auto &word : wordDict)
            {
                if (i >= word.size())
                {
                    if (word == s.substr(i - word.size(), word.size()) && dp[i - word.size()])
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};