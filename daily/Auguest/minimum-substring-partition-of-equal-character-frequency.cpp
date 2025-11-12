#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 0;

        int record[26];
        auto is_balance = [&record]() -> bool {
            int val = 0;
            for (auto i : record)
            {
                if (i != 0)
                {
                    if (val == 0)
                        val = i;
                    else if (val != i)
                        return false;
                }
            }
            return true;
        };

        for (int i = 1; i <= n; ++i)
        {
            int res = INT_MAX;
            for (int j = i; j >= 1; --j)
            {
                ++record[s[j - 1] - 'a'];
                if (dp[j - 1] != -1 && is_balance())
                {
                    res = min(dp[j - 1] + 1, res);
                }
            }
            dp[i] = res;
            memset(record, 0, sizeof record);
        }

        return dp[n];
    }
};