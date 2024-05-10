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
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;

        // vi dp(sum / 2 + 1);
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     for (int j = dp.size() - 1; j > 0; --j)
        //     {
        //         if (nums[i] <= j)
        //         {
        //             dp[j] = max(dp[j - nums[i]] + nums[i], dp[j]);
        //         }
        //     }
        // }
        // if (dp.back() == sum / 2) return true;
        // return false;

        bitset<10001> bt(1);
        for (int n : nums)
        {
            // 利用位运算保存所有nums中元素能达到地和
            bt |= bt << n;
        }
        return bt[sum / 2];
    }  
};
