#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), [](const vector<int> &v1, const vector<int> &v2) { return v1[0] < v2[0]; });
        vector<pair<long long, long long>> dp(rides.size(), {-1, -1});
        return back_tracking(0, -1, rides, dp);
    }

    long long back_tracking(int start, int end, vector<vector<int>> &rides, vector<pair<long long, long long>> &dp)
    {
        if (start == rides.size()) return 0;

        long long res1 = 0, res2 = 0;
        auto a = rides[start][0], b = rides[start][1], c = rides[start][2];
        auto &tar = dp[start];

        if (a >= end)
        {
            if (tar.first == -1)
                tar.first = back_tracking(start + 1, b, rides, dp) + b - a + c;
            res1 = tar.first;
        }
        
        if (tar.second == -1)
            tar.second = back_tracking(start + 1, end, rides, dp);
        res2 = tar.second;
        return max(res1, res2);
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> sam = {{2,5,4}, {1,5, 1}};
    Solution().maxTaxiEarnings(5, sam);
    return 0;
}
