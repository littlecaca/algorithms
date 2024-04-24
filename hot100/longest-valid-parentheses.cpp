#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        vector<int> dp(s.size() + 1);
        dp[0] = 0;
        stack<int> sta;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                sta.push(i);
            else
            {
                if (!sta.empty())
                {
                    auto left = sta.top();
                    sta.pop();
                    dp[i + 1] = i - left + 1 + dp[left];
                    res = max(res, dp[i + 1]);
                }
            }
        }
        return res;
    }
};