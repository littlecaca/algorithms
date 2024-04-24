#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1));
        for (string &s : strs)
        {
            pair<int, int> count = cal(s);
            for (int i = m; i >= 0; --i)
            {
                for (int j = n; j >= 0; --j)
                {
                    if (i >= count.first && j >= count.second)
                        dp[i][j] = max(dp[i][j], dp[i - count.first][j - count.second] + 1);
                }
            }
        }
        return dp[m][n];
    }

    pair<int, int> cal(const string &s)
    {
        int m = 0, n = 0;
        for (auto c : s)
        {
            if (c == '1') ++n;
            else ++m;
        }
        return {m, n};
    }
};