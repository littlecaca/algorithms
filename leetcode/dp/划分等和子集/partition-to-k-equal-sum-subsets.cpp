#include <bitset>
#include <numeric>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;


template <typename T>
bool chmin(T &x, const T& y)
{
    if (x <= y) return false;
    x = y; return true;
}

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // =================================
        //          状态压缩+动态规划
        // =================================
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int tar = sum / k;

        vi dp(1 << n, -1);
        dp[0] = 0;
        for (int s = 1; s < dp.size(); ++s)
        {
            for (int i = 0; i < n; ++i)
            {
                if ((s & (1 << i)) == 0) continue;
                int s1 = s & ~(1 << i);
                if (dp[s1] >= 0 && nums[i] + dp[s1] <= tar)
                {
                    dp[s] = (nums[i] + dp[s1]) % tar;
                    break;
                }
            }
        }
        return dp.back() == 0;
    }
};