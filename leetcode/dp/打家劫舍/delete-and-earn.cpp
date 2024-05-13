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
#include <map>

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
    int deleteAndEarn(vector<int>& nums) {

        // ====================================
        //          排序 + 动态规划
        //              O(nlogn)
        //=====================================
        // map<int, int> counts;
        // for (auto n : nums)
        //     counts[n] += n;
        // vi unique_nums(counts.size());
        // vi values(counts.size());
        // int i = 0;
        // for (auto &p : counts)
        // {
        //     unique_nums[i] = p.first;
        //     values[i] = p.second;
        //     ++i;
        // }
            
        // vi dp(counts.size() + 1);
        // dp[1] = values[0];
        // for (int i = 2; i < dp.size(); ++i)
        // {
        //     if (unique_nums[i - 2] != unique_nums[i - 1] - 1)
        //         dp[i] = values[i - 1] + dp[i - 1];
        //     else
        //         dp[i] = max(dp[i - 1], dp[i - 2] + values[i - 1]);
        // }
        // return dp.back();


        // ====================================
        //             动态规划
        // ====================================
        

    }
};